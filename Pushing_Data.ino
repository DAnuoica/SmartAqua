 //pushing DATA
void pushData(){
    
    if(trueTime(beforeMinute)) {
    String pathPush = "Hoca/logs/";
    pathPush+=getTime();
    String pathTemp = pathPush + "/Temp";
    String pathLight = pathPush + "/Light";
    Serial.println(pathTemp);
    Firebase.setInt(pathTemp, getCurrentTemp());
    Firebase.setInt(pathLight, getCurrentLight());
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
//      return;
  }
    }
  }

  
