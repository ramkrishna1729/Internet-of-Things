
#include <LiquidCrystal.h>

int wheel=8;
int gasSensorA = A5;

float sensorValue = 0 ;
int outputValue = 0;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
char * messageHigh = "                High Alcohol Content                ";
char * messageLow = "                Low Alcohol Content                ";
char * messageNo = "                No Alcohol Content                ";
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
  Serial.begin(9600);
  pinMode (gasSensorA, INPUT);
  pinMode(wheel,OUTPUT);
 
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display 
  lcd.print("ALCOHOL DETECTOR");
}

void loop() 
{
  sensorValue = analogRead(gasSensorA);
  Serial.println(sensorValue, DEC);
  lcd.setCursor(0,1);
  lcd.print("Content: ");
  lcd.print(sensorValue);
  delay(1000);
  
  if (sensorValue > 300)
   {
    
    digitalWrite(wheel,LOW);
    for (int letter = 0; letter <= strlen(messageHigh) - 16; letter++) //From 0 to upto n-16 characters supply to below function
  	{
    	showHigh(0, letter);
  	}     

  }
  else if (sensorValue < 300 && sensorValue > 100)
   {
    digitalWrite(wheel,LOW);
    for (int letter = 0; letter <= strlen(messageLow) - 16; letter++) //From 0 to upto n-16 characters supply to below function
  	{
    	showLow(0, letter);
  	}  
  }
   else {
   
     digitalWrite(wheel,HIGH);
     
    for (int letter = 0; letter <= strlen(messageNo) - 16; letter++) //From 0 to upto n-16 characters supply to below function
  	{
    	showNo(0, letter);
  	}
  
  }
  
}

void showNo(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 1);
  for (int letter = startLetter; letter <= startLetter + 15; letter++) // Print only 16 chars in Line #2 starting 'startLetter'
  {
    lcd.print(messageNo[letter]);
  }
  lcd.print(" ");
  delay(100);
}

void showLow(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 1);
  for (int letter = startLetter; letter <= startLetter + 15; letter++) // Print only 16 chars in Line #2 starting 'startLetter'
  {
    lcd.print(messageLow[letter]);
  }
  lcd.print(" ");
  delay(100);
}

void showHigh(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 1);
  for (int letter = startLetter; letter <= startLetter + 15; letter++) // Print only 16 chars in Line #2 starting 'startLetter'
  {
    lcd.print(messageHigh[letter]);
  }
  lcd.print(" ");
  delay(100);
}=