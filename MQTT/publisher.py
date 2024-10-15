import time
import paho.mqtt.client as mqtt_client
from uuid import getnode as get_mac
import hashlib
import serial

port_photo = "COM6"
connection_photo = serial.Serial(port_photo, baudrate=9600, timeout=1)

broker = "broker.emqx.io"

h = hashlib.new('sha256')
mac = get_mac()
h.update(str(mac).encode())
pub_id = h.hexdigest()[:10]
print(f"Listen me at id {pub_id}")

client = mqtt_client.Client(
    mqtt_client.CallbackAPIVersion.VERSION2,
    pub_id
)

print("Connecting to broker", broker)
client.connect(broker)
client.loop_start()
print("Publishing")

try:
    for i in range(100):
        connection_photo.write(b'p')
        photo_val = connection_photo.read(1)

        if photo_val:
            photo_val = int.from_bytes(photo_val, "big") * 4
            print(f"Освещенность: {photo_val}")
            client.publish(f"laba/d874890809/leds/state3", photo_val)
            print(f"Published light value: {photo_val}")

        time.sleep(2)

finally:
    client.disconnect()
    client.loop_stop()
    connection_photo.close()
