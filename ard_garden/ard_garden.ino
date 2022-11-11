#include <SoftwareSerial.h>
 
SoftwareSerial nodemcu(2,3);
 
int sensor1 = A0;
int sensor2 = A1; 
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
 
int sdata1 = 0; // sensor1 data
int sdata2 = 0; // sensor2 data
int sdata3 = 0; // sensor3 data
int sdata4 = 0; // sensor4 data
int sdata5 = 0; // sensor5 data
 
String cdata; // complete data, consisting of sensors values
 
void setup()
{
Serial.begin(9600); 
nodemcu.begin(9600);
 
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(sensor5, INPUT);
pinMode(4, OUTPUT); // TO ON/OFF VARIABLE RESISTOR
digitalWrite(4, HIGH); 
 
}
 
void loop()
{
  
    sdata1 = analogRead(sensor1);
    sdata2 = analogRead(sensor2);
    sdata3 = analogRead(sensor3);
    sdata4 = analogRead(sensor4);
    sdata5 = analogRead(sensor5);
   cdata = cdata + sdata1+","+sdata2+","+sdata3+","+sdata4+","+sdata5; // comma will be used a delimeter
   Serial.println(cdata); 
   nodemcu.println(cdata);
   delay(2000); // 100 milli seconds
   cdata = ""; 
 
}
