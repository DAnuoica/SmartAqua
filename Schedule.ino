void setSchedule(bool payload) {
  checkSchedule = payload;
  if(payload) {
    led_START = Firebase.getString("HoCa/Led/start");if(led_START !="") remainSchedule++;
    
    led_STOP = Firebase.getString("HoCa/Led/stop");if(led_STOP !="") remainSchedule++;
    
    feed_START = Firebase.getString("HoCa/Feed/start");if(feed_START !="") remainSchedule++;

<<<<<<< HEAD
    coolwarm_START = Firebase.getString("HoCa/Request/start");if(coolwarm_START !="") remainSchedule++;
    coolwarm_STOP = Firebase.getString("HoCa/Request/stop");if(coolwarm_STOP !="") remainSchedule++;
=======
    cool-warm_START = Firebase.getString("HoCa/Request/start");if(cool-warm_START !="") remainSchedule++;
    cool-warm_STOP = Firebase.getString("HoCa/Request/stop");if(cool-warm_STOP !="") remainSchedule++;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
    
    oxi_START = Firebase.getString("HoCa/Oxi/start");if(oxi_START !="") remainSchedule++;
    oxi_STOP = Firebase.getString("HoCa/Oxi/stop");if(oxi_STOP !="") remainSchedule++;
    }
  
  }
void doSchedule() {
  if(checkSchedule) {
    String timeS = getTime();
//HEN GIO NONG LANH
<<<<<<< HEAD
  if(coolwarm_START == timeS) {
    keyTemp == true ; 
    //stopWarmerCooler(0); 
    stopWarmerCooler(); 
    if(remainSchedule == 0)  checkSchedule = false;
  }
  if(coolwarm_STOP == timeS) {
=======
  if(cool-warm_START == timeS) {
    keyTemp == true ; 
    stopWarmerCooler(0); 
    if(--remainSchedule == 0)  checkSchedule = false;
  }
  if(cool-warm_STOP == timeS) {
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
      keyTemp = false;
      switchCooler(false);
      switchWarmer(false);
      switchPurifier(false);
      Serial.println("Tat so nong lanh...");
<<<<<<< HEAD
      if(remainSchedule == 0)  checkSchedule = false;
=======
      if(--remainSchedule == 0)  checkSchedule = false;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }
  //HEN GIO LED
  if(led_START == timeS) {
    if(digitalRead(PinLed) == LOW) {
      switchLed(true);
      Serial.println("LED sang");
      Firebase.setBool("HoCa/Led/value", true);
      Firebase.setString("HoCa/Led/start", "null");
      }
<<<<<<< HEAD
    if(remainSchedule == 0)  checkSchedule = false;
=======
    if(--remainSchedule == 0)  checkSchedule = false;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }
  if(led_STOP == timeS) {
    if(digitalRead(PinLed) == HIGH) {
      switchLed(false);
      Serial.println("LED tat");
      Firebase.setBool("HoCa/Led/value", false);
      Firebase.setString("HoCa/Led/stop", "null");
      }
<<<<<<< HEAD
   if(remainSchedule == 0)  checkSchedule = false;
=======
   if(--remainSchedule == 0)  checkSchedule = false;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }

  
  if(oxi_START == timeS) {
    if(digitalRead(PinOxi) == LOW) {
      switchOxi(true);
      Serial.println("OXI bat");
      Firebase.setBool("HoCa/Oxi/value", true);
      Firebase.setString("HoCa/Oxi/start", "null");
      }
<<<<<<< HEAD
      if(remainSchedule == 0)  checkSchedule = false;
=======
      if(--remainSchedule == 0)  checkSchedule = false;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }
  if(oxi_STOP == timeS) {
    if(digitalRead(PinOxi) == HIGH) {
      switchLed(false);
      Serial.println("OXI tat");
      Firebase.setBool("HoCa/Oxi/value", false);
      Firebase.setString("HoCa/test/stop", "null");
      }
<<<<<<< HEAD
    if(remainSchedule == 0)  checkSchedule = false;
=======
    if(--remainSchedule == 0)  checkSchedule = false;
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }
    }
  
  }
