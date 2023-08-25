#define ledPin1 D1
#define ledPin2 D3
#define ledPin3 D4
#define ldrPin A0

#include <ESP8266WiFi.h>;
#include <ThingSpeak.h>;
#include <DHT.h>
// #include <WiFiClient.h>;

// DHT11 definitions
#define DHTPIN D2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// WiFi credentials
const char* ssid = "AndroidAP_7280";
const char* password = "passward";

// WiFi client
WiFiClient client;

// ThingSpeak credentials
unsigned long channelID = 1979815;
const char* writeAPIKey = "Q4XROTWR3PHK1N42";
const char* readAPIKey = "23D24DP12OL5PR1R";

// User defined global variables
int ldrValue = 0;
int fetchedLDRValue = 0;
float temperature = 0;
float humidity = 0;
float fetchedTemperature = 0;
float fetchedHumidity = 0;

// User defined constants
const int ldrThreshold = 256;
const int temperatureThreshold = 32;
const int humidityThreshold = 70;

void setup() 
{
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}
void loop() 
{
  ldrValue = analogRead(ldrPin);
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.println("Local readings");
  Serial.println("_______________________________");
  Serial.println(ldrValue);

  Serial.println(temperature);
  Serial.println(humidity);

  ThingSpeak.setField(1, ldrValue);
  ThingSpeak.setField(2, temperature);
  ThingSpeak.setField(3, humidity);
  ThingSpeak.writeFields(channelID, writeAPIKey);
  
  fetchedLDRValue = ThingSpeak.readIntField(channelID, 1, readAPIKey);
  fetchedTemperature = ThingSpeak.readIntField(channelID, 2, readAPIKey);
  fetchedHumidity = ThingSpeak.readIntField(channelID, 3, readAPIKey);
  
  Serial.println("Fetched readings");
  Serial.println("_______________________________");
  Serial.println(fetchedLDRValue);
  Serial.println(fetchedTemperature);
  Serial.println(fetchedHumidity);

  if (fetchedLDRValue < ldrThreshold) 
  {
    digitalWrite(ledPin1, HIGH);
  } 

  else 
  {
    digitalWrite(ledPin1, LOW);
  }
  
  if (fetchedTemperature > temperatureThreshold) 
  {
    digitalWrite(ledPin2, HIGH);
  } 
  else 
  {
    digitalWrite(ledPin2, LOW);
  }
  if (fetchedHumidity > humidityThreshold) 
  {
    digitalWrite(ledPin3, HIGH);
  } 
  else 
  {
    digitalWrite(ledPin3, LOW);
  }
  delay(15000);
  } 
