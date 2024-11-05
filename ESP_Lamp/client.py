import time
import paho.mqtt.client as mqtt
import questionary

MQTT_BROKER = "broker.emqx.io"
MQTT_PORT = 1883
light_id = questionary.text("Введите ID"":").ask()
MQTT_TOPIC = f"home/light/{light_id}"
initial_light_duration = 20
minimum_light_duration = 10
decrement_duration = 1
current_duration = initial_light_duration

lamp_state = False
def on_connect(client, userdata, flags, rc):
    print(f"Connected with result code {rc}")
def publish_light_state(state):
    client.publish(MQTT_TOPIC, state)
def manage_light():
    global current_duration, lamp_state
    while True:
        current_second = int(time.time()) % 60
        if current_second == 20:
            end_time = 20 + current_duration
            print(f"Лампочка включена на {current_duration} секунд (с 20 по {end_time} секунду).")
            publish_light_state("ON")
            lamp_state = True
            while int(time.time()) % 60 < end_time:
                time.sleep(0.1)
            print("Лампочка выключена")
            publish_light_state("OFF")
            lamp_state = False

            if current_duration > minimum_light_duration:
                current_duration -= decrement_duration
            else:
                current_duration = initial_light_duration
        time.sleep(0.1)

def on_message(client, userdata, msg):
    global lamp_state
    message = msg.payload.decode()
    if message == "OFF" and lamp_state:
        print("Лампочка выключена через MQTT")
        publish_light_state("OFF")
        lamp_state = False
if __name__ == "__main__":
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(MQTT_BROKER, MQTT_PORT, 60)
    client.subscribe(MQTT_TOPIC)
    client.loop_start()

    try:
        manage_light()
    except KeyboardInterrupt:
        print("Остановка клиента")
    finally:
        client.loop_stop()
        client.disconnect()
