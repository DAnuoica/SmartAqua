void catchEvent() {
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
/////////////////// Dieu khien OXI
    if (path == "/Oxi/value")
    {   
    bool payload = event.getBool("data");
    switchOxi(payload);
    digitalWrite(PinOxi, payload);
    Serial.print("data Oxi: ");
    Serial.println(payload);
    }
    if (path == "/Schedule")
    {   
    bool payload = event.getBool("data");
    if(payload) setSchedule(payload);
    }
    /////////////////// Dieu khien FEED
    if (path == "/Feed/value")
    {
       bool payload = event.getBool("data");
       switchFeed(payload);
    }
/////////////////// Dieu khien LED
    if (path == "/Led/value")
    {
    bool payload = event.getBool("data");
    Serial.println("Thay doi LED");
    switchLed(payload);
    
   // pcf8574.digitalWrite(PinLED, payload);
    }
    if (path == "/Purifier/value")
    {
    bool payload = event.getBool("data");
    Serial.println("Thay doi may bom");
    switchLed(payload);
    
    
    if (path == "/Request") 
    {
      Serial.println("Vao che do tu chinh nhiet do");
      int fbTemp  = event.getInt("data");
      int currentTemp = getCurrentTemp();
       Serial.print("Nhiet do hien tai cua ho ca:");
       Serial.println(currentTemp);
        if(currentTemp > fbTemp) 
        {
          //giam nhiet do 
          switchPurifier(true);
          switchCooler(true);
         // pcf8574.digitalWrite(PinCooler, false); 
         // Serial.println("Hay giam nhiet do");
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
