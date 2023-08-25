const int LED1 = 13;
int flag=0;

const int ENA = 8;
const int IN1=9;//left side of motor when you see bot from back
const int IN2=10;
const int ENB = 11;//right side of motor when you see bot from back
const int IN3=5;
const int IN4=6;
int frontIR=12;
int sensorValue[]={A0,A1,A2,A3,A4,A5,2,3};

void setup() 
{
  // put your setup code here, to run once:

  pinMode(LED1 , OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(12,INPUT);
  

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);

  //forward();
  //delay(2000);
}

void readIRs()
{  
  sensorValue[1] =digitalRead(2);
  sensorValue[2] =digitalRead(3);
  sensorValue[3] =digitalRead(A5);
  sensorValue[4] =digitalRead(A4);
  sensorValue[5] =digitalRead(A3);
  sensorValue[6] =digitalRead(A2);
  sensorValue[7] =digitalRead(A1);
  sensorValue[8] =digitalRead(A0);

  frontIR = digitalRead(12);
  Serial.print("SensorValue: ");
  Serial.println(sensorValue[0]);
  Serial.println(sensorValue[1]);
  Serial.println(sensorValue[2]);
  Serial.println(sensorValue[3]);
  Serial.println(sensorValue[4]);
  Serial.println(sensorValue[5]);
  Serial.println(sensorValue[6]);
  Serial.println(sensorValue[7]);
}

void moveMotor(int speedLeft, int speedRight, int dirLeft, int dirRight)
{
  Serial.print("Motor Vals: ");
  Serial.print(speedLeft);
  Serial.print(" ");
  Serial.print(speedRight);
  Serial.print(" ");
  Serial.print(dirLeft);
  Serial.print(" ");
  Serial.println(dirRight);
  
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  if(dirLeft==1){
    analogWrite(IN1, speedLeft);
    analogWrite(IN2, 0);
  }
  else
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, speedLeft);
  }

  if(dirRight==1){
    analogWrite(IN3, speedRight);
    analogWrite(IN4, 0);
  }
  else
  {
    analogWrite(IN3, 0);
    analogWrite(IN4, speedRight);
  }

}

void blink(){
  Serial.println("Blink for checkpoint");
  digitalWrite(LED1,HIGH);
  delay(300);
  digitalWrite(LED1,LOW);
}

void loop() 
{
  readIRs();

//  forward
  if((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))
   {
    moveMotor(147,147,1,1);
   }
//  right
  if(((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
   ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0)))
   {
    moveMotor(107,147,1,1);
   }
  if(((sensorValue[0] == 0)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0)))
   {
    moveMotor(61,147,1,1);
   }
   if((((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 0)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))))
   {
    moveMotor(107,107,-1,1);
   }
//  left
  if(((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 0)&&(sensorValue[7] == 0)))
   {
    moveMotor(147,107,1,1);
   }
  if(((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 0))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 0)))
   {
    moveMotor(147,61,1,1);
   }
   if(((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 0)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 0)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 0)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 0)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
  ((sensorValue[0] == 0)&&(sensorValue[1] == 0)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1)))   {
    moveMotor(107,107,1,-1);
   }
   //checkpoint or end
   if(((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
    ((sensorValue[0] == 0)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
    ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 0)))
   {
    if(frontIR==0){
      flag=flag+1;
      if(flag==1){
        moveMotor(53,53,1,1);
      }
      
      if((((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
    ((sensorValue[0] == 0)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 1))||
    ((sensorValue[0] == 1)&&(sensorValue[1] == 1)&&(sensorValue[2] == 1)&&(sensorValue[3] == 1)&&(sensorValue[4] == 1)&&(sensorValue[5] == 1)&&(sensorValue[6] == 1)&&(sensorValue[7] == 0)))
   &&(frontIR==0)){
        moveMotor(0,0,1,1);
        Serial.println("ENDpoint");
      }
    }
    else{
      blink();
     moveMotor(147,147,1,1);
    }
   }
}