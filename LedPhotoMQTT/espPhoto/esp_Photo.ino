#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void setup() {
  Serial.begin(115200);
  WIFI_init(false);
  MQTT_init();
  pinMode(A0, INPUT);
}

void loop() {
  mqtt_cli.loop();
  int light_level = analogRead(A0);
  char light_str[8];
  snprintf(light_str, sizeof(light_str), "%d", light_level);
  mqtt_cli.publish(sensor_topic, light_str);
  delay(5000);
}
