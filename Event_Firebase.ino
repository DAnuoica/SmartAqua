void catchEvent(int &Mode) {
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
//      break;
    }
     if (path == "/Temp") 
    {
      delay(3000);
      Serial.println("Vao che do tu chinh nhiet do");
      int fbTemp  = event.getInt("data");
      int currentTemp = getCurrentTemp();
      delay(2000);
       Serial.print("Nhiet do hien tai cua ho ca:");
       Serial.println(currentTemp);
      delay(2000); //vao lan dau
        if(currentTemp > fbTemp) 
        {
          //giam nhiet do  
          Serial.println("Hay giam nhiet do");
        };
        if(currentTemp < fbTemp) 
        {
          //tang nhiet do  
          Serial.println("Hay tang nhiet do");
        };
        keyTemp = true;
      }
  }
    }
}
