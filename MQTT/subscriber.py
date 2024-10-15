import time
import paho.mqtt.client as mqtt_client
from uuid import getnode as get_mac
import hashlib
import serial

port_led = "COM6"
connection_led = serial.Serial(port_led, baudrate=9600, timeout=1)

broker = "broker.emqx.io"
pub_id = "d874890809"

if not pub_id:
    raise RuntimeError("Publisher id is not defined")

h = hashlib.new('sha256')
mac = get_mac()
h.update(str(mac).encode())
sub_id = h.hexdigest()[10:20]

def on_message(client, userdata, message):
    data = str(message.payload.decode("utf-8"))
    print("Received message =", data)

    try:
        photo_val = int(data)
        if photo_val > 500:
            connection_led.write(b'u')
            print("Светодиод включен.")
        else:
            connection_led.write(b'd')
            print("Светодиод выключен.")
    except ValueError:
        print("Received non-integer value, ignoring.")

client = mqtt_client.Client(
    mqtt_client.CallbackAPIVersion.VERSION2,
    sub_id
)

client.on_message = on_message

print("Connecting to broker", broker)
client.connect(broker)
client.loop_start()
print("Subscribing")
client.subscribe("laba/d874890809/leds/state3")
try:
    while True:
        time.sleep(1)

finally:
    client.disconnect()
    client.loop_stop()
    connection_led.close()
