#include <WiFi.h>

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

    while(status != WL_CONNECTED){
      Serial.println(status);
      Serial.println("Attempting to connect to Networks");
      status = WiFi.begin("zyj","12345678");
      delay(10000);
    }

    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.println(ip);

}

void loop() {
  // put your main code here, to run repeatedly:

}



