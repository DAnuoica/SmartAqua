void controlFeed(bool value) {
    pcf8574.digitalWrite(PinMotor, !value); 
    analogWrite(in3, 255);
    pcf8574.digitalWrite(in4, HIGH);
    delay(5000);
    String path = "HoCa/Feed";
    Firebase.setBool(path, false);
    pcf8574.digitalWrite(PinMotor, HIGH);
   }
