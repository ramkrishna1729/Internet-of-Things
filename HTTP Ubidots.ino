ldr_ubidots_publish_http

#include <ESP8266WiFi.h>;  //Define Instances and Constants
#include <WiFiClient.h>; 
#include "Ubidots.h"
const char UBIDOTS_TOKEN= "BBFF-x5e4HGEd4o1V116M34KiuJqD6qU3Cx"; // Put here your Ubidots TOKEN
const char* WIFI SSID "AEIE_AP"; // Put here your Wi-Fi SSID
const char* WIFI PASS - "12345678"; // Put here your Wi-Fi password

Ubidots ubidots (UBIDOTS_TOKEN, UBI_HTTP);
int val;
int tempPin - AB; 
WiFiClient client;
Auxiliar Functions // Put here your auxiliar functions

Main Functions
void setup() {
Serial.begin(115200); 
ubidots.wifiConnect(WIFI SSIDWIFI PASS):// ubidots.setDebug(true); // Uncomment this line for printing debug messages
}

void loop() {
val analogRead(tempPin); //float mv- (val / 1024.0) 3300; //float cel = mv / 10;
Serial.println(val);
ubidots.add("wxyz", val); // Change for your variable name
bool bufferSent = false;
bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id
if (bufferSent)   // Do something if values were sent properly Serial.println("Values sent by the device");
{
delay(5000);
}