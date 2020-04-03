#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

  #define WIFI_SSID "     "   //Thay wifi và mật khẩu
  #define WIFI_PASSWORD "tamthang"

#define PinMode 16
#define PinOxi 5
#define PinFeed 4
#define PinLED 13

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

    if (path == "/")
    {
    JsonVariant payload = event.getJsonVariant("data");
    Serial.print("data: ");
  //  bool checkMode = payload["Mode"];
    bool checkOxi = payload["Oxi"];
    bool checkFeed = payload["Feed"];
    bool checkLED = payload["LED"];
    
    digitalWrite(PinMode, false);
    digitalWrite(PinOxi, checkOxi);
    digitalWrite(PinFeed, checkFeed);
    digitalWrite(PinLED, checkLED);
    payload.printTo(Serial);
    }
/////////////////// Dieu khien OXI
    if (path == "/Oxi")
    {   
    bool payload = event.getBool("data");
    digitalWrite(PinOxi, payload);
    Serial.print("data Oxi: ");
    Serial.println(payload);
    }
    /////////////////// Dieu khien FEED
    if (path == "/Feed")
    {
    bool payload = event.getBool("data");
    digitalWrite(PinFeed, payload);
    Serial.print("data Feed: ");
    Serial.println(payload);
    }
/////////////////// Dieu khien LED
    if (path == "/LED")
    {
    bool payload = event.getBool("data");
    digitalWrite(PinLED, payload);
    Serial.print("data LED: ");
    Serial.println(payload);
    }
  
    if (path == "/Mode")
    {
      Mode = event.getInt("data");
      digitalWrite(PinMode, true);
      break;
    }
  }
    }
  
  }
  while(Mode == 2) //che do auto 
  {
    String path = "/Hoca";
    FirebaseObject object = Firebase.get(path);
    int Mode = object.getInt("Mode");
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
