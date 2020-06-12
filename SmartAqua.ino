#include <FirebaseArduino.h>          //
#include <ESP8266WiFi.h>              //
#define WIFI_SSID "Tuấn Thành"        //
#define WIFI_PASSWORD "tuanthanh0"      //
////////////////////////////////////////
#include <OneWire.h>                  //
#include <DallasTemperature.h>        //
#define ONE_WIRE_BUS 13 //D7              // Temp Module
OneWire oneWire(ONE_WIRE_BUS);        //
DallasTemperature sensors(&oneWire);  //
////////////////////////////////////////////////////////////////////////// 
#include <NTPClient.h>                                                  //
#include <ESP8266WiFi.h>                                                //
#include <WiFiUdp.h>                                                    //  TIME
const long utcOffsetInSeconds = 25200;                                  //
WiFiUDP ntpUDP;                                                         //
NTPClient timeClient(ntpUDP, "vn.pool.ntp.org", utcOffsetInSeconds);    //
//////////////////////////////////////////////////////////////////////////
#include <BH1750.h>        //
BH1750 lightMeter;        /// Light Module 
///////////////////////////////
#include "Arduino.h"         // Mở rộng Module
#include "PCF8574.h"         // https://github.com/xreef/PCF8574_library
PCF8574 pcf8574(0x20);       //
///////////////////////////////

const int trig = 16;     // D2  cam SR04
const int echo = 14;     // D5  vang SR04
int in3 = 12;            // D6 in4 of Feed Motor

#define PinMotor 2        //P2 Relay of Feed
#define PinCooler 3       //P3 Relay of Cooler
#define PinLed 4          //P4
int in4 = 5;              //P5 in4 of Feed Motor
#define PinOxi 6          //P6 Relay of Oxi  
#define PinWarmer 7       //P7 Relay of Warmer

bool keyTemp = false;
bool keyTime = false;
bool checkPush = false;
bool checkSchedule = false;
int remainSchedule = 0;

 String led_START;
   String  led_STOP;

   String  coolwarm_START;
    String coolwarm_STOP;
    String oxi_START;
    String oxi_STOP;
    String feed_START;


#include "WorkScheduler.h"   // TIMER
#include "Timer.h"     
WorkScheduler *batsukien;
WorkScheduler *dieukhiennonglanh;
WorkScheduler *baothucan;
WorkScheduler *guidulieu;
WorkScheduler *hengio;



void setup() {
Serial.begin(9600);

Timer::getInstance()->initialize();

batsukien =  new WorkScheduler(500UL, catchEvent);
dieukhiennonglanh =  new WorkScheduler(1000UL, stopWarmerCooler);
baothucan =  new WorkScheduler(5000UL, notiFeed);
guidulieu =  new WorkScheduler(30000UL, trueTime);
hengio =  new WorkScheduler(10000UL, doSchedule);


pcf8574.pinMode(PinLed, OUTPUT);
pcf8574.pinMode(PinMotor, OUTPUT);
pcf8574.pinMode(PinCooler, OUTPUT);
pcf8574.pinMode(PinOxi, OUTPUT);
pcf8574.pinMode(PinWarmer, OUTPUT);
pinMode(in3, OUTPUT);
pcf8574.pinMode(in4, OUTPUT);  
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  pcf8574.begin();

sensors.begin(); // temp module

Wire.begin(); //
lightMeter.begin(); // Light Module

// connect to wifi.
WiFi.mode(WIFI_STA);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
int timeOut=30;
 while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
      timeOut--;
      if(timeOut==0) {
        Serial.println("Bat servo sg90");
//        servoOpen();
        while(WiFi.status() != WL_CONNECTED) {
          WiFi.reconnect();
          delay(10000);
          if(WiFi.status() == WL_CONNECTED) {
            Serial.println("Co dien lai");
            Serial.println("Tat servo sg90");
 //           servoClose();
          }
          else Serial.println("Chua co dien lai");
          }
       }
  }

Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin("smartaquarium-92af6.firebaseio.com");
Firebase.stream("/HoCa"); 
//Serial.println(getCurrentTemp());
}
void loop() { 
  
   Timer::getInstance()->update();
  batsukien->update();
  dieukhiennonglanh->update();
  baothucan->update();
  guidulieu->update();
  hengio->update();
  Timer::getInstance()->resetTick();
}
