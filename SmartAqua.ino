////////////////////////////////////////
#include <OneWire.h>                  //
#include <DallasTemperature.h>        //
#define ONE_WIRE_BUS 13               // Temp Module
OneWire oneWire(ONE_WIRE_BUS);        //
DallasTemperature sensors(&oneWire);  //
////////////////////////////////////////

#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

  #define WIFI_SSID "     "   //Thay wifi và mật khẩu
  #define WIFI_PASSWORD "tamthang"

#define PinMode 16
#define PinOxi 5
#define PinFeed 4
#define PinLED 13

bool keyTemp = false;

void initData() {
    Firebase.setInt("Mode", 0); // chua set mode
    Firebase.setBool("LED", false);
    Firebase.setBool("Oxi", false);
    Firebase.setBool("Feed", false);
    }
void setup() {
Serial.begin(9600);

pinMode(PinMode, OUTPUT);
pinMode(PinOxi, OUTPUT);
pinMode(PinFeed, OUTPUT);
pinMode(PinLED, OUTPUT);

sensors.begin(); // temp module

// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());

Firebase.begin("arduinotest-7d858.firebaseio.com"); // thay bằng địa chỉ ứng dụng của bạn
//initData();
Firebase.stream("/Hoca"); 
}


void loop() {
  String path = "/Hoca";
  FirebaseObject object = Firebase.get(path);
  int Mode = object.getInt("Mode");
  while(Mode == 1) //che do manual
  {   
    catchEvent(Mode);
  if(keyTemp == true)//vao lan sau
        {
          FirebaseObject object = Firebase.get(path);
          int fbTemp  = object.getInt("Temp");
          int currentTemp = getCurrentTemp();
          delay(1000);
          Serial.println("Vao che do thay doi nhiet do");
          Serial.print("Nhiet do hien tai cua ho ca:");
          delay(500);
          Serial.println(currentTemp);
          delay(500);
          Serial.print("Nhiet do tren Firebase: ");
          delay(500);
          Serial.println(fbTemp);
          delay(500);
          //kiem tra neu currentTemp = fbTemp thi keyTemp = false
          if(currentTemp == fbTemp) 
          {
            keyTemp = false;
            // Dong thoi tat so nong lanh
            Serial.println("Tat so nong lanh...");
          } else { Serial.println("Chua tat so");}
          delay(1000);
        }
  }



  
  while(Mode == 2) //che do auto 
  {
    Serial.println("Che do Auto");
    String path = "/Hoca";
    FirebaseObject object = Firebase.get(path);
    //Mode = object.getInt("Mode");
    if (Firebase.available()) {
    FirebaseObject event = Firebase.readEvent();
    String eventType = event.getString("type");
    eventType.toLowerCase();
    
    Serial.print("event: ");
    Serial.println(eventType);
    if (eventType == "put") {
    Serial.print("data: ");
    Serial.println(event.getString("data"));
    String path = event.getString("path");
    String data = event.getString("data");

    if (path == "/Mode")
    {
      Serial.println("Thoat khoi che do AUTO");
      delay(2000);
      Mode = event.getInt("data");
      break;
    }
    }
    }
  }
}
