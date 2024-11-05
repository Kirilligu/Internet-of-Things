#include <EEPROM.h>
String ssidAP = "WIFI_LAMP"; 
String passwordAP = "WIFILAMP123"; 
String ssidCLI = "";
String passwordCLI = "";
char* mqtt_broker = "broker.emqx.io";
const int mqtt_port = 1883;
const char* light_id = "1";
const char* mqtt_topic = "home/light/1";
const int led = 2;  
const int ssidAddress = 0;
const int passwordAddress = 50;

