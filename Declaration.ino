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
#include <Servo.h>           // 
#define SERVO1_PIN 0         //
#define SERVO2_PIN 2         //
Servo gServo1;               //
Servo gServo2;               //
///////////////////////////////
#include "WorkScheduler.h"   // TIMER
#include "Timer.h"     
WorkScheduler *batsukien;
WorkScheduler *dieukhiennonglanh;
WorkScheduler *baothucan;
WorkScheduler *guidulieu;
WorkScheduler *hengio;
/////////////////////////////
const int trig = 16;     // D2  cam SR04
const int echo = 14;     // D5  vang SR04
int in3 = 12;            // D6 in4 of Feed Motor

#define PinMotor 2        //P2 Relay of Feed
#define PinCooler 3       //P3 Relay of Cooler
#define PinLED 4          //P4
int in4 = 5;              //P5 in4 of Feed Motor
#define PinOxi 6          //P6 Relay of Oxi  
#define PinWarmer 7       //P7 Relay of Warmer

bool keyTemp = false;
bool keyTime = false;
bool checkPush = false;
bool checkSchedule = false;
byte remainSchedule = 0;

   String led_START;
   String  led_STOP;

   String  cool-warm_START;
    String cool-warm_STOP;
