/*
      red       VCC  ---- 5V (Arduino)
      black     GND  ---- GND (Arduino)
      yellow    DATA ----  2  (Arduino)  16 (wemos)    
 */
 
int getCurrentTemp() 
{ 
 sensors.requestTemperatures();
 Serial.println(sensors.getTempCByIndex(0));
 return round (sensors.getTempCByIndex(0));
} 

void stopWarmerCooler (bool &keyTemp)
{
   if(keyTemp == true)//vao lan sau
  {
//    String path = "/HoCa";
//    FirebaseObject object = Firebase.get(path);
//    int fbTemp  = object.getInt("Temp");
//    int fbTemp = Firebase.getInt("HoCa/Temp");
    int fbTemp = Firebase.getInt("HoCa/Request");
    int currentTemp = getCurrentTemp();
 //   delay(100);
    Serial.println("Vao che do thay doi nhiet do");
    Serial.print("Nhiet do hien tai cua ho ca:");
  //  delay(100);
    Serial.println(currentTemp);
   // delay(100);
    Serial.print("Nhiet do tren Firebase: ");
    //delay(100);
    Serial.println(fbTemp);
    //delay(100);
    
    //kiem tra neu currentTemp = fbTemp thi keyTemp = false
    if(currentTemp == fbTemp) 
    {
      keyTemp = false;
      // Dong thoi tat so nong lanh
      pcf8574.digitalWrite(PinCooler, true); 
      Serial.println("Tat so nong lanh...");
    } else { Serial.println("Chua tat so");}
    delay(50);
  }
  delay(100);
}
