#include <ESP8266WebServer.h>
#include "Config.h"

ESP8266WebServer server(80);
void handleRoot() {                         
    String html = "<html><head><meta charset=\"UTF-8\"></head><body>"
                  "<h1>Настройка WiFi</h1>"
                  "<form action=\"/connect\" method=\"GET\">"
                  "SSID: <input type=\"text\" name=\"ssid\"><br>"
                  "Password: <input type=\"password\" name=\"password\"><br><br>"
                  "<input type=\"submit\" value=\"Подключиться\">"
                  "</form>"
                  "</body></html>";
    server.send(200, "text/html", html);
}

void handleConnect() {  
    if (server.hasArg("ssid") && server.hasArg("password")) {
        String ssidCLI = server.arg("ssid");
        String passwordCLI = server.arg("password");

        Serial.println("Подключение к WiFi сети: " + ssidCLI);
        Serial.println("Пароль: " + passwordCLI);

        ::ssidCLI = ssidCLI;
        ::passwordCLI = passwordCLI;

        if (StartCLIMode()) {
            saveCredentials();
            String response = "<html><head><meta charset=\"UTF-8\"></head><body><h1>Подключение успешно!</h1></body></html>";
            server.send(200, "text/html", response);
        } else {
            String response = "<html><head><meta charset=\"UTF-8\"></head><body><h1>Ошибка подключения. Проверьте SSID и пароль.</h1></body></html>";
            server.send(200, "text/html", response);
            StartAPMode();
        }
    } else {
        server.send(400, "text/html", "Ошибка: Отсутствуют параметры подключения.");
    }
}

void handleNotFound() {
    server.send(404, "text/plain", "404: Not found"); 
}

void server_init() {
    server.on("/", HTTP_GET, handleRoot);     
    server.on("/connect", HTTP_GET, handleConnect);  
    server.onNotFound(handleNotFound);        
    
    server.begin();                          
    Serial.println("HTTP server started");    
}

