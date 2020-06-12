bool Outage() {
  return true;
  }
void setup() {
Serial.begin(9600);
Setting();
if(Outage() == true) {
  //lift  servos
  //setup access point
  //do nothing else
  }
  else {
    //drop servos 
    //try connecting wifi until connected
    }
//after connect again wifi (or initial connection), get all status from Firebase
//reset firebase status
//write retrieved status had been saved 

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
        servoOpen();
        while(WiFi.status() != WL_CONNECTED) {
          WiFi.reconnect();
          delay(10000);
          if(WiFi.status() == WL_CONNECTED) {
            Serial.println("Co wifi lai");
            Serial.println("Tat servo sg90");
            servoClose();
          }
          else Serial.println("Chua co dien lai");
          }
       }
  }

Serial.println();
Serial.print("connected: ");
Serial.println("Tat servo sg90");
servoClose();
Serial.println(WiFi.localIP());
//Firebase.begin("smartaquarium-92af6.firebaseio.com");
Firebase.begin("smartaqua-beb30.firebaseio.com");
Firebase.stream("/HoCa"); 
Serial.println(getCurrentTemp());
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
