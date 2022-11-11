#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#include <TinyGPSPlus.h> //https://github.com/mikalhart/TinyGPSPlus
#include <TinyGsmClient.h> //https://github.com/vshymanskyy/TinyGSM
char auth[] = "OlT7nBOr8VuJe1LVbqTAPEfIDXzDthMQ";
char ssid[] = "IEM IEDC LAB";
char pass[] = "IEMIEDC501";



//GPS Module Settings
//GPS Module RX pin to ESP32 17
//GPS Module TX pin to ESP32 16
#define RX D7
#define TX D6

TinyGPSPlus gps;

WidgetMap myMap(V0);
BlynkTimer timer;
int pointIndex = 1;

void setup() {
   
  //Set Serial monitor baud rate
  Serial.begin(115200);
  Serial.println("esp8266 serial initialize");
  delay(10);
  

  // Restart takes quite some time
  // To skip it, call init() instead of restart()

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, sendToBlynk);
}

void loop() {
  

      sendToBlynk();


  Blynk.run();
  timer.run();
  
} 

void sendToBlynk()
{

  if (gps.location.isValid() )
  {
    //get latitude and longitude
    float latitude = (gps.location.lat());
    float longitude = (gps.location.lng());


    Blynk.virtualWrite(V1, String(latitude, 6));
    Blynk.virtualWrite(V2, String(longitude, 6));
 
    
  }
}
