#include <WiFi.h>


#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Scan Networks");
    int numSsid = WiFi.scanNetworks();
    Serial.println("number of available networks:");
    Serial.println(numSsid);
}

void loop() {
  // put your main code here, to run repeatedly:

}
