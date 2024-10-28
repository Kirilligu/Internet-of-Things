import time
import paho.mqtt.client as paho

broker = "broker.emqx.io"
topic = "home/light_sensor"
light_threshold = 500

led_state = "OFF"

def on_message(client, userdata, message):
    global led_state
    light_level = int(message.payload.decode("utf-8"))

    if light_level > light_threshold:
        led_state = "ON"
    else:
        led_state = "OFF"

    print(f"Получено значение освещенности: {light_level}")
    print(f"Состояние светодиода: {led_state}")

client = paho.Client("ClientID")
client.on_message = on_message

client.connect(broker)
client.subscribe(topic)
client.loop_start()

try:
    print("Ожидание сообщений на топике:", topic)
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("Отключение от брокера...")
    client.loop_stop()
    client.disconnect()
