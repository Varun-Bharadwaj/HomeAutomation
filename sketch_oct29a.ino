#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "Microcloud_2";
const char *password = "654321";

ESP8266WebServer server(80);

const int led = 2;  //GPIO2

void handleRoot() {

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
  <head>\    
    <title>MicroCloud</title>\
  </head>\
  <body>\
    <h3>You are connected on MicroCloud #2!</h3>\
    <p>Status: Light ON</h1></p>\
    <p><a href=\"http://192.168.4.1/on\"><h1>Turn ON</h1></a></p>\
    <p></p>\
    <p><a href=\"http://192.168.4.1/off\"><h1>Turn OFF</h1></a></p>\           
  </body>\
</html>"
    );
  server.send ( 200, "text/html", temp );  
  
}

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  pinMode(led, OUTPUT);
  digitalWrite ( led, HIGH );

  server.on("/", handleRoot);
  server.on ( "/on", turnON );    
  server.on ( "/off", turnOFF );
  server.begin();
  Serial.println("HTTP server started");
  
}

void turnON(){

  digitalWrite ( led, HIGH );

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
  <head>\    
    <title>MicroCloud</title>\
  </head>\
  <body>\
    <h3>Request: Light ON</h3>\
    <p></p>\
    <p>Status: Light ON</h1></p>\
    <p><a href=\"http://192.168.4.1/on\"><h1>Turn ON</h1></a></p>\
    <p></p>\
    <p><a href=\"http://192.168.4.1/off\"><h1>Turn OFF</h1></a></p>\       
  </body>\
</html>"
  );

  server.send ( 200, "text/html", temp);
  
}

void turnOFF(){

  digitalWrite ( led, LOW );

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
  <head>\    
    <title>MicroCloud</title>\
  </head>\
  <body>\
    <h3>Request: Light OFF</h3>\
    <p>Status: Light OFF</p>\
    <p><a href=\"http://192.168.4.1/on\"><h1>Turn ON</h1></a></p>\
    <p></p>\
    <p><a href=\"http://192.168.4.1/off\"><h1>Turn OFF</h1></a></p>\       
  </body>\
</html>"
  );

  server.send ( 200, "text/html", temp);
  
}

void loop() {
  server.handleClient();
}
