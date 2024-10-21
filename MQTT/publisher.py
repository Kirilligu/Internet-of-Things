import time
import paho.mqtt.client as mqtt_client
from uuid import getnode as get_mac
import hashlib
import serial
from collections import deque

port_photo = "COM6"
connection_photo = serial.Serial(port_photo, baudrate=9600, timeout=1)
broker = "broker.emqx.io"

h = hashlib.new('sha256')
mac = get_mac()
h.update(str(mac).encode())
pub_id = h.hexdigest()[:10]
print(f"ID издателя: {pub_id}")

client = mqtt_client.Client(mqtt_client.CallbackAPIVersion.VERSION2, pub_id)
client.connect(broker)
print("Подключено к брокеру.")
client.loop_start()

client.publish("lab/pub_id", pub_id)
print("ID опубликован.")

def normalize_photo_value(raw_value, min_value=0, max_value=1023, norm_min=0, norm_max=100):
    return int((raw_value - min_value) * (norm_max - norm_min) / (max_value - min_value) + norm_min)

queue = deque(maxlen=100)

def calculate_average():
    return sum(queue) // len(queue) if queue else 0

stream_state = False
inst_time = time.time()

min_val = float('inf')
max_val = float('-inf')

publish_instant_interval = 1.0
publish_average_interval = 0.1
last_instant_publish_time = 0
last_average_publish_time = 0
last_minmax_publish_time = 0

try:
    while True:
        command = input("Введите команду (on для активации, off для деактивации): ").strip().lower()

        if command == "on":
            if not stream_state:
                stream_state = True
                print("Поток запущен")

                while stream_state:
                    connection_photo.write(b'p')
                    photo_val = connection_photo.read(1)

                    if photo_val:
                        raw_value = int.from_bytes(photo_val, "big") * 4
                        normalized_value = normalize_photo_value(raw_value)

                        queue.append(normalized_value)
                        average_value = calculate_average()

                        if normalized_value < min_val:
                            min_val = normalized_value
                        if normalized_value > max_val:
                            max_val = normalized_value

                        current_time = time.time()

                        if current_time - last_instant_publish_time > publish_instant_interval:
                            last_instant_publish_time = current_time
                            client.publish(f"lab/{pub_id}/photo/instant", normalized_value)
                            print(f"Значение освещенности: {normalized_value}")

                        if current_time - last_average_publish_time > publish_average_interval:
                            last_average_publish_time = current_time
                            client.publish(f"lab/{pub_id}/photo/average", average_value)
                            print(f"Среднее значение: {average_value}")

                        if current_time - last_minmax_publish_time > 5:
                            last_minmax_publish_time = current_time
                            client.publish(f"lab/{pub_id}/photo/min", min_val)
                            client.publish(f"lab/{pub_id}/photo/max", max_val)
                            print(f"минимум: {min_val}, максимум: {max_val}")

                    time.sleep(0.01)

        elif command == "off":
            if stream_state:
                stream_state = False
                print("Поток остановлен")

finally:
    client.disconnect()
    client.loop_stop()
    connection_photo.close()
