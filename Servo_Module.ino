void servoOpen(){
   gServo1.write(170);
   gServo2.write(10);   
    for(int i=160;i>30;i=i-20) {
      gServo1.write(i);
      gServo2.write(180-i);
      delay(1000);
      }
  }
void servoClose() {
  for(int i=40;i<180;i=i+20) {
      gServo1.write(i);
      gServo2.write(180-i);
      delay(1000);
      }
  
  }
