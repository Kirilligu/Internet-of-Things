#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void blinkLED(int duration, int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(led, HIGH);
        delay(duration);
        digitalWrite(led, LOW);
        delay(duration);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(led, OUTPUT);
    EEPROM.begin(512);
    loadCredentials();
    blinkLED(1000, 2);
    if (!StartCLIMode()) {
        StartAPMode();
    }
    server_init();
    MQTT_init();
}

void loop() {
    server.handleClient();
    mqtt_cli.loop();
    if (WiFi.status() == WL_CONNECTED) {
        if (isInternetAvailable()) {
            MQTT_reconnect();
            if (lampState) {
                digitalWrite(led, HIGH);
            } else {
                digitalWrite(led, LOW);
            }
        } else {
            if (!lampState) {
                blinkLED(1000);
            }
            StartAPMode();
        }
    } else {
        if (!lampState) {
            blinkLED(1000);
        }
        StartAPMode();
    }
}
