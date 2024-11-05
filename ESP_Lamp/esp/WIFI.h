#include "Config.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

void saveCredentials() {
    for (int i = 0; i < ssidCLI.length(); i++) {
        EEPROM.write(ssidAddress + i, ssidCLI[i]);
    }
    for (int i = ssidCLI.length(); i < 50; i++) {
        EEPROM.write(ssidAddress + i, 0);
    }
    for (int i = 0; i < passwordCLI.length(); i++) {
        EEPROM.write(passwordAddress + i, passwordCLI[i]);
    }
    for (int i = passwordCLI.length(); i < 50; i++) {
        EEPROM.write(passwordAddress + i, 0);
    }
    EEPROM.commit();
    Serial.println("данные сохранены");
}

void loadCredentials() {
    char ssidBuffer[50] = {0};
    for (int i = 0; i < 50; i++) {
        ssidBuffer[i] = EEPROM.read(ssidAddress + i);
    }
    ssidCLI = String(ssidBuffer).c_str();
    char passwordBuffer[50] = {0};
    for (int i = 0; i < 50; i++) {
        passwordBuffer[i] = EEPROM.read(passwordAddress + i);
    }
    passwordCLI = String(passwordBuffer).c_str();
    Serial.println("данные загружены: SSID: " + ssidCLI + ", Пароль: " + passwordCLI);
}
bool isInternetAvailable() {
    WiFiClient client;
    if (client.connect("www.google.com", 80)) {
        client.print("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n");
        unsigned long timeout = millis();
        while (client.available() == 0) {
            if (millis() - timeout > 5000) {
                return false;
            }
        }
        while (client.available()) {
            String line = client.readStringUntil('\n');
            if (line.startsWith("HTTP/1.1 200")) {
                return true;
            }
        }
    }
    return false;}

void StartAPMode() {
    IPAddress apIP(192, 168, 4, 1);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssidAP.c_str(), passwordAP.c_str());
    Serial.println("WiFi запущен в режиме AP с именем: " + ssidAP);
}

bool StartCLIMode() {
    Serial.println("Пытаемся подключиться к WiFi...");
    WiFi.begin(ssidCLI.c_str(), passwordCLI.c_str());
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 30000) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nПодключение выполнено!");
        Serial.print("IP адрес: ");
        Serial.println(WiFi.localIP());
        WiFi.softAPdisconnect(true);
        Serial.println("Точка доступа отключена");
        
        return true;
    } else {
        Serial.println("\nОшибка: Не удалось подключиться к WiFi");
        return false;
    }
}

