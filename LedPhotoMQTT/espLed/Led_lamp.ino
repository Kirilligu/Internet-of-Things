#include "Config.h"
#include "Server.h"
#include "WIFI.h"
#include "MQTT.h"

void setup() {
    Serial.begin(115200);
    WIFI_init(false);
    MQTT_init();
    pinMode(led, OUTPUT);
    mqtt_cli.subscribe(sensor_topic);
}

void loop() {
    mqtt_cli.loop();
}
