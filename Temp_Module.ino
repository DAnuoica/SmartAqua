/*
      red       VCC  ---- 5V (Arduino)
      black     GND  ---- GND (Arduino)
      yellow    DATA ----  2  (Arduino)  16 (wemos)    
 */
 
int getCurrentTemp() 
{ 
 sensors.requestTemperatures();
// Serial.println(sensors.getTempCByIndex(0));
  delay(50);
 return round (sensors.getTempCByIndex(0));
} 

void stopWarmerCooler (byte mode)
{
    if (keyTemp == true){
    int requestTemp = Firebase.getInt("HoCa/Request");
    int currentTemp = getCurrentTemp();
    Serial.println("Vao che do thay doi nhiet do");
    Serial.print("Nhiet do hien tai cua ho ca:");
    Serial.println(currentTemp);
    Serial.print("Nhiet do tren Firebase: ");
    Serial.println(requestTemp);
    //kiem tra neu currentTemp = fbTemp thi keyTemp = false
    if(currentTemp == requestTemp) 
    {
     if(mode==1) keyTemp = false;
      switchCooler(false);
      switchWarmer(false);
      switchPurifier(false);
      Serial.println("Tat so nong lanh...");
    }
    else if(currentTemp < requestTemp) {
      Serial.println("Nguoi dung yeu cau tang nhiet do");
      switchCooler(false); // Firstly, switch off the Cooler
      switchWarmer(true); // Switch on the Warmer
      }
    else if (currentTemp > requestTemp) {
      Serial.println("Nguoi dung yeu cau giam nhiet do");
      switchCooler(true); // Firstly, switch off the Cooler
      switchWarmer(false); // Switch on the Warmer
      }
    delay(50);
    }
}
