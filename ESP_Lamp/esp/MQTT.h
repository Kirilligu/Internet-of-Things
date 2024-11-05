#include <PubSubClient.h>
#include "Config.h"

WiFiClient espClient;
PubSubClient mqtt_cli(espClient);
bool lampState = false;
void blinkLED(int duration, int times = 1);

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    if (message == "ON") {
        lampState = true;
        digitalWrite(led, HIGH);
        Serial.println("Лампочка включена");
    } else if (message == "OFF") {
        lampState = false;
        digitalWrite(led, LOW);
        Serial.println("Лампочка выключена");
    }
}
void MQTT_init() {
    mqtt_cli.setServer(mqtt_broker, mqtt_port);
    mqtt_cli.setCallback(callback);
    while (!mqtt_cli.connected()) {
        String client_id = "esp8266-" + String(WiFi.macAddress());
        Serial.print("Клиент " + client_id);
        Serial.println(" подключается к публичному MQTT брокеру\n");
        if (mqtt_cli.connect(client_id.c_str())) {
            Serial.println("MQTT подключен");
            mqtt_cli.subscribe(mqtt_topic);
            blinkLED(200, 2);
        } else {
            Serial.print("не удалось, статус ");
            Serial.println(mqtt_cli.state());
            blinkLED(100);
            delay(2000);
        }
    }  
}
void MQTT_reconnect() {
    if (mqtt_cli.connected()) {
        return;
    }
    String client_id = "esp8266-" + String(WiFi.macAddress());
    Serial.print("Клиент " + client_id);
    Serial.println(" подключается к публичному MQTT брокеру");

    while (!mqtt_cli.connected()) {
        Serial.print("Подключение к MQTT...");
        blinkLED(100);
        if (mqtt_cli.connect(client_id.c_str())) {
            Serial.println("подключено");
            mqtt_cli.subscribe(mqtt_topic);
            blinkLED(200, 2);
        } else {
            Serial.print("не удалось, статус ");
            Serial.println(mqtt_cli.state());
            delay(2000);
        }
    }
}

