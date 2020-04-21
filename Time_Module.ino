/*
   Kết nối:
          DS1307            Arduino
            VCC               5V
            GND               GND
            SDA               SDA
            SCL               SCL
*/

bool trueTime() {
  strDateTime dateTime;
  dateTime = NTPch.getNTPtime(7.0, 0);
  if(dateTime.valid){
    if(dateTime.second %10 ==0) return true;
    }
  return false;
  
  }
void getTime(int i){
  Serial.println(i);
  dateTime = NTPch.getNTPtime(7.0, 0);
    if(dateTime.valid){
        Serial.println("inside");
        NTPch.printDateTime(dateTime);

        byte actualHour = dateTime.hour;
        byte actualMinute = dateTime.minute;
        byte actualsecond = dateTime.second;
        int actualyear = dateTime.year;
        byte actualMonth = dateTime.month;
        byte actualday =dateTime.day;
        byte actualdayofWeek = dateTime.dayofWeek;
        }
        else 
        {
          delay(1000);
          getTime(i++);
        }
      delay(1000);
  }

//  if(dateTime.valid){
//    Serial.println("OK thoi gian");
//  String currentTime="";
//  currentTime+=dateTime.day;
//  currentTime+="/";
//  currentTime+=dateTime.month;
//  currentTime+="-";
//  currentTime+=dateTime.hour;
//  currentTime+=":";
//  currentTime+=dateTime.minute;
//  currentTime+=":";
//  currentTime+=dateTime.second;
//  return currentTime;  
//  } else Serial.println("Loi thoi gian");
