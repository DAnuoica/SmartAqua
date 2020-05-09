#include <FirebaseArduino.h>          //
#include <ESP8266WiFi.h>              //
#define WIFI_SSID "Redmi"        //
#define WIFI_PASSWORD "tuanthanh0"      //
////////////////////////////////////////
#include <OneWire.h>                  //
#include <DallasTemperature.h>        //
#define ONE_WIRE_BUS 13               // Temp Module
OneWire oneWire(ONE_WIRE_BUS);        //
DallasTemperature sensors(&oneWire);  //
///////////////////////////////////////
#include <NTPtimeESP.h>             //
#define DEBUG_ON                    //
NTPtime NTPch("ch.pool.ntp.org");   //Time Module
strDateTime dateTime;               //     
//////////////////////////////////////
#include <BH1750.h>        //
BH1750 lightMeter;        /// Light Module 
///////////////////////////////
#include "Arduino.h"         // Mở rộng Module
#include "PCF8574.h"         // https://github.com/xreef/PCF8574_library
PCF8574 pcf8574(0x20);       //
///////////////////////////////

int Mode =1;

const int trig = 4;     // P0 chân trig của HC-SR04
const int echo = 5;     // P1 chân echo của HC-SR04

#define PinOxi 5
//#define PinFeed 4
#define PinLED 13
#define PinMotor 2 //P2
#define PinCooler 3 //P3


int in3 = 14;   //in 3 cam 5
int in4 = 16; // in4  cam 2
//int enB = 3;   // en cam 0

bool keyTemp = false;
bool keyTime = false;
byte beforeMinute=60;

//void initData() {
//    Firebase.setInt("Mode", 0); // chua set mode
//    Firebase.setBool("LED", false);
//    Firebase.setBool("Oxi", false);
//    Firebase.setBool("Feed", false);
//    }
void setup() {
Serial.begin(9600);

//pinMode(PinMode, OUTPUT);
pinMode(PinOxi, OUTPUT);
//pinMode(PinFeed, OUTPUT);
pinMode(PinLED, OUTPUT);
pcf8574.pinMode(PinMotor, OUTPUT);
pcf8574.pinMode(PinCooler, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
pcf8574.pinMode(trig, OUTPUT);
pcf8574.pinMode(echo, INPUT);
  pcf8574.begin();


sensors.begin(); // temp module
//pcf8574.Wire.begin(D4, D3); //
//lightMeter.begin(); // Light Module

Wire.begin(); //
lightMeter.begin(); // Light Module

// connect to wifi.
WiFi.mode(WIFI_STA);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin("smartaquarium-92af6.firebaseio.com");

Firebase.stream("/HoCa"); 
Serial.println(getCurrentTemp());

}

void loop() { 
  
//  String path = "/HoCa";
//  FirebaseObject object = Firebase.get(path);
//  int Mode = object.getInt("Mode");
  while(Mode == 1) //che do manual
  { 
    Serial.println("Dang o trong loop while");
    pushData();
    if (Firebase.available()) { catchEvent();};
 //   notiFeed();
    stopWarmerCooler(keyTemp);
    delay(50);
  }
     
}
