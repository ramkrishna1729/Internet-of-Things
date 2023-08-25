#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid= "AEIE_AP";
const char * password = "12345678";

WiFiClient client;

unsigned long myChannelNumber = 2018402;
const char* myWriteAPIKey ="MC3UNU0UQO8I1MQS";
const char* myReadAPIKey = "0XPK60ZVZIKKC52J";

int readval;
int led = D4;
int val =0;
int ldr = A0;

void setup() {
  Serial.begin(115200);
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);
  WiFi.begin(ssid,password);
  ThingSpeak.begin(client);

}

void loop() {
  val = analogRead(ldr);
  Serial.println("value from ldr : %d");
  Serial.println(val);

  ThingSpeak.setField(1,val);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  readval = ThingSpeak.readIntField(myChannelNumber,1,myReadAPIKey);
   Serial.println("value from ldr from thingspeak: ");
    Serial.println(readval);

   if(readval < 200)
   {
    digitalWrite(led,HIGH);
   }
   else
   {
    digitalWrite(led,LOW);
   }
   delay(1000);
}
  