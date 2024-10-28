#include <PubSubClient.h>

PubSubClient mqtt_cli(wifiClient);
const int light_threshold = 500;

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
    char message[length + 1];
    strncpy(message, (char*)payload, length);
    message[length] = '\0';
    Serial.println(message);
    Serial.println("-----------------------");

    if (String(topic) == "home/light_sensor") {
        int light_level = atoi(message);
        Serial.print("Light level: ");
        Serial.println(light_level);
    if (light_level > light_threshold) {
        digitalWrite(led, HIGH);
        Serial.println("LED ON");
    } else {
        digitalWrite(led, LOW);
        Serial.println("LED OFF");
    }
    }
}

void MQTT_init() {
    mqtt_cli.setServer(mqtt_broker, mqtt_port);
    mqtt_cli.setCallback(callback);
    while (!mqtt_cli.connected()) {
        String client_id = "esp8266-" + String(WiFi.macAddress());
        Serial.print("The client " + client_id);
        Serial.println(" connects to the public mqtt broker\n");
        if (mqtt_cli.connect(client_id.c_str())) {
            Serial.println("MQTT Connected");
        } else {
            Serial.print("failed with state ");
            Serial.println(mqtt_cli.state());
            delay(2000);
        }
    }
}
