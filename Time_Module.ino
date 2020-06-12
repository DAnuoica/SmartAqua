void trueTime() {
  timeClient.update();
//  h = timeClient.getHours();
int  m = timeClient.getMinutes();
  if(m % 2 == 0) {
    if(!checkPush) {
      pushData();
      checkPush = true;
      }
    }
  else checkPush = false;
  }
  
  String getTime(){
    timeClient.update();
    return timeClient.getFormattedTime();
    }
