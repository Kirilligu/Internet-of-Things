import time
import paho.mqtt.client as mqtt_client
from uuid import getnode as get_mac
import hashlib
import serial

port_led = "COM3"
connection_led = serial.Serial(port_led, baudrate=9600, timeout=1)
broker = "broker.emqx.io"
pub_id = None

h = hashlib.new('sha256')
mac = get_mac()
h.update(str(mac).encode())
sub_id = h.hexdigest()[10:20]

old_photo = None
datastore = []
threshold = 0

def avg(data):
    return sum(data) / len(data) if data else 0
def on_message(client, userdata, message):
    global old_photo, datastore, threshold, pub_id
    d = str(message.payload.decode("utf-8"))
    print(f"Получено {d} ")
    if message.topic == "lab/pub_id":
        pub_id = d
        print(f"Получен pub_id: {pub_id}")
        client.subscribe(f"lab/{pub_id}/photo/instant")
        client.subscribe(f"lab/{pub_id}/photo/min")
        client.subscribe(f"lab/{pub_id}/photo/max")
        client.subscribe(f"lab/{pub_id}/photo/average")
    if pub_id and message.topic == f"lab/{pub_id}/photo/instant":
        try:
            new_photo = float(d)
        except ValueError:
            print(f"Получено некорректное значение для мгновенного: {d}, игнорируется.")
            return
        datastore.append(new_photo)
        if len(datastore) > 5:
            datastore.pop(0)
        if len(datastore) >= 2:
            avg_value = avg(datastore)
            print(f"Среднее последних значений: {avg_value}")
            if new_photo > avg_value:
                connection_led.write(b'u')
                print("Светодиод ВКЛ из-за увеличения яркости.")
            else:
                connection_led.write(b'd')
                print("Светодиод ВЫКЛ из-за уменьшения яркости.")
    elif pub_id and message.topic == f"lab/{pub_id}/photo/min":
        try:
            min_value = float(d)
            threshold = (min_value + threshold) / 2
            print(f"Обновлено минимальное значение: {min_value}, порог: {threshold}")
        except ValueError:
            print(f"Получено некорректное значение для мин: {d}")
    elif pub_id and message.topic == f"lab/{pub_id}/photo/max":
        try:
            max_value = float(d)
            threshold = (threshold + max_value) / 2
            print(f"Обновлено максимальное значение: {max_value}, порог: {threshold}")
        except ValueError:
            print(f"Получено некорректное значение для макс: {d}, игнорируется.")

    if old_photo is not None and threshold > 0:
        if old_photo > threshold:
            connection_led.write(b'u')
            print("Светодиод ВКЛ")
        else:
            connection_led.write(b'd')
            print("Светодиод ВЫКЛ")

    old_photo = new_photo if 'new_photo' in locals() else old_photo

client = mqtt_client.Client(mqtt_client.CallbackAPIVersion.VERSION2, sub_id)
client.on_message = on_message
print("Подключение к брокеру", broker)
client.connect(broker)
client.loop_start()
print("Подписка на тему pub_id")
client.subscribe("lab/pub_id")

try:
    while True:
        time.sleep(1)
finally:
    client.disconnect()
    client.loop_stop()
    connection_led.close()
