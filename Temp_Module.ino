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
    String path = "/Hoca";
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
