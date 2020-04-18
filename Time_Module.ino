/*
   Kết nối:
          DS1307            Arduino
            VCC               5V
            GND               GND
            SDA               SDA
            SCL               SCL
*/

void setupTimeModule(){
 Serial.begin(9600);
 if (! rtc.begin())
 {
   Serial.print("Couldn't find RTC");
   while (1);
 }

  if (! rtc.isrunning())
 {
   Serial.print("RTC is NOT running!");
   Serial.println();
 }
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}
bool trueTime() {
  DateTime now = rtc.now();
  if(now.hour()%2==0 && now.minute()==0 && now.second()==0) {
    delay(1000);
      return true;
      }
  return false;
  
  }
String getTime(){
  DateTime now = rtc.now();
  String currentTime="";
  //currentTime+=daysOfTheWeek[now.dayOfTheWeek()];
  currentTime+=now.day();
  currentTime+="/";
  currentTime+=now.month();
  currentTime+="-";
  currentTime+=now.hour();
  currentTime+=":";
  currentTime+=now.minute();
  currentTime+=":";
  currentTime+=now.second();
  return currentTime;
  
  }
