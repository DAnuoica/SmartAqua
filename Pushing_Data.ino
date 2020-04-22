 //pushing DATA
void pushData(){
    
    if(trueTime(beforeMinute)) {
    String pathPush = "Hoca/logs/";
    pathPush+=getTime();
    Serial.println(pathPush);
    Firebase.setInt(pathPush, getCurrentTemp());
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
//      return;
  }
    }
  }

  
