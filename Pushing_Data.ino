 //pushing DATA
void pushData(){
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["time"] = getTime();
  root["temp"] = getCurrentTemp();
  root["light"] = getCurrentLight();
  root["led"] = Firebase.getBool("HoCa/Led");
  String name = Firebase.push("HoCa/logs", root);
  if (Firebase.failed()) {
      Serial.println(Firebase.error());  
//      return;
  }
    delay(50);
  }













 
//void pushData(){
//    String path = "HoCa/Temp";
//    String pathPush = "HoCa/logs/";
//    pathPush+=getTime();
//    String pathTemp = pathPush + "Temp";
//    String pathLight = pathPush + "Light";
//    String pathTest = pathPush + "Test";
////    Serial.println(pathTemp);
//    int currentTemp = getCurrentTemp();
//    Serial.println(currentTemp);
//    Firebase.setInt(pathTemp, currentTemp);
//    Firebase.setInt(pathLight, getCurrentLight());
//    Firebase.setInt(pathTest, 100);
//  //  Firebase.setInt(path, currentTemp);
//  if (Firebase.failed()) {
//      Serial.print("setting /number failed:");
//      Serial.println(Firebase.error());  
////      return;
//  }
//    delay(50);
//  }

  
