#include <WiFi.h>

int status = WL_IDLE_STATUS;
//监听端口
WiFiServer server(8080);
    
void setup() {

  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    while(status != WL_CONNECTED){
      Serial.println(status);
      Serial.println("Attempting to connect to Networks");
      status = WiFi.begin("zyj","12345678");
      delay(10000);
    }
    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.println(ip);
    server.begin();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(client){
    Serial.println("New client");
    String currentLine = "";
    while(client.connected()){
      if(client.available()){
      char c = client.read();
      Serial.write(c);
      if(c == '\n'){
         if(currentLine.length() == 0){
          server.println("<html>");
          server.println("<head>");
          server.println("<title> LED </title>");
          server.println("</head>");
          server.println("<body>");
          server.println("<p> hello world </p>");
          server.println("</body>");
          server.println("</html>");
          server.println();
          break;
         }
         else{
          currentLine = "";
         }
      }
      else if(c != '\r'){
        currentLine+=c;
       // Serial.println(currentLine);
       if(currentLine.endsWith("GET /On")){
           digitalWrite(13,HIGH);
           Serial.println("light on");
       }
       if(currentLine.endsWith("GET /Off")){
           digitalWrite(13,LOW);       
           Serial.println("light off");
       }
      }
      
     }
    }
  client.stop();
  Serial.println("stop");
  }
}



