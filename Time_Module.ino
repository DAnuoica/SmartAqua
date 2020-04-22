/*
          DS1307            Arduino
            VCC               5V
            GND               GND
            SDA               SDA
            SCL               SCL
*/

bool trueTime(byte &beforeMinute) {
//  strDateTime dateTime;
  dateTime = NTPch.getNTPtime(7.0, 0);
  if(dateTime.valid){
    if(dateTime.minute != beforeMinute && dateTime.minute %1 == 0)
    {
      beforeMinute = dateTime.minute;
      Serial.println("True Time");
      return true;
    } 
    else return false;
   
    } else 
        {
          delay(100);
          return trueTime(beforeMinute);
        }
  return false;
  
  }
String getTime(){
  dateTime = NTPch.getNTPtime(7.0, 0);
    if(dateTime.valid){
        //NTPch.printDateTime(dateTime);
          String currentTime="";
          currentTime+=dateTime.day;
          currentTime+="-";
          currentTime+=dateTime.month;
          currentTime+=" ";
          currentTime+=dateTime.hour;
          currentTime+=":";
          currentTime+=dateTime.minute;
          return currentTime;  
        }
        else 
        {
          delay(100);
          return getTime();
        }
  }
