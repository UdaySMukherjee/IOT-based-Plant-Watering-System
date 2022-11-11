#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

 
char auth[] = "UpXo0hKV11Nc5RRqlA5cqPdAB7TrW5IV";
char ssid[] = "IEM IEDC LAB";
char pass[] = "IEMIEDC501";
 
BlynkTimer timer;

int setmoisture=30;

int mspercent_1; // moisture value in percentage
int mspercent_2;
int mspercent_3;
int mspercent_4;
int mspercent_5;

int Relay = D4; // you can connect a dc or ac water pump
 
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
 
int firstVal, secondVal,thirdVal,fourthVal,fifthVal; // sensors 
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}
 
 
 
void setup()
{
  // Debug console
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
    timer.setInterval(1000L,sensorvalue1); 
     timer.setInterval(1000L,sensorvalue2);
     timer.setInterval(1000L,sensorvalue3);
     timer.setInterval(1000L,sensorvalue4);
     timer.setInterval(1000L,sensorvalue5);
     
 
}
 
void loop()
{
   if (Serial.available() == 0 ) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
   }
   
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata; 
   // Serial.print(rdata);
    if( rdata == '\n')
    {
   //  Serial.println(myString); 
  // Serial.println("fahad");
// new code
String l = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2); 
String o = getValue(myString, ',', 3); 
String p = getValue(myString, ',', 4); 
 
 
firstVal = l.toInt();
secondVal = m.toInt();
thirdVal = n.toInt();
fourthVal = o.toInt();
fifthVal = p.toInt();
 
  myString = "";
// end new code
    }
  }
 
}
 
void sensorvalue1()
{
int sdata_1 = firstVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
mspercent_1 = map(sdata_1,208,1019,100,0); // To display the soil moisture value in percentage 
   Serial.print("Soil_1 ");
  Serial.println(mspercent_1);
  
  if (mspercent_1<setmoisture ){
        digitalWrite(D4,HIGH);
    delay(8000); 
    digitalWrite(D4,LOW); 
  }

  
  Blynk.virtualWrite(V2, mspercent_1);
 
}
void sensorvalue2()
{
int sdata_2 = secondVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  mspercent_2 = map(sdata_2,224,1019,100,0); // To display the soil moisture value in percentage 
   Serial.print("Soil_2 ");
  Serial.println(mspercent_2);
  
   if (mspercent_2<setmoisture ){
        digitalWrite(D4,HIGH);
    delay(8000); 
    digitalWrite(D4,LOW); 
  }

  Blynk.virtualWrite(V3, mspercent_2);
 
}

void sensorvalue3()
{
int sdata_3 = thirdVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
     mspercent_3 = map(sdata_3,215,1018,100,0); // To display the soil moisture value in percentage 
   Serial.print("Soil 3 ");
  Serial.println(mspercent_3);

   if (mspercent_3<setmoisture ){
    digitalWrite(D4,HIGH);
    delay(8000); 
    digitalWrite(D4,LOW);
  }

  Blynk.virtualWrite(V4, mspercent_3);
 
}

void sensorvalue4()
{
int sdata_4 = fourthVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
     mspercent_4 = map(sdata_4,264,1006,100,0); // To display the soil moisture value in percentage 
   Serial.print("Soil_4 ");
  Serial.println(mspercent_4);

   if (mspercent_4<setmoisture ){
        digitalWrite(D4,HIGH);
    delay(8000); 
    digitalWrite(D4,LOW); 
  }

  Blynk.virtualWrite(V5, mspercent_4);
 
}

void sensorvalue5()
{
int sdata_5 = fifthVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  mspercent_5 = map(sdata_5,471,887,100,0); // To display the soil moisture value in percentage 
   Serial.print("Soil_5 ");
   Serial.println(mspercent_5);
   
   if (mspercent_5<setmoisture ){
        digitalWrite(D4,HIGH);
    delay(8000); 
    digitalWrite(D4,LOW); 
  }

  Blynk.virtualWrite(V6, mspercent_5);
 
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
