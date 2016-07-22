#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);


  int numSsid = WiFi.scanNetworks();
  
  for(int thisNet = 0; thisNet < numSsid; thisNet++){
       Serial.print(WiFi.SSID(thisNet));
       Serial.print("          ");
       Serial.print(WiFi.RSSI(thisNet));
       Serial.print("          ");
       Serial.print(WiFi.encryptionType(thisNet));
       Serial.println("");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}



