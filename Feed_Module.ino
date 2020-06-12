void controlFeed(bool value) {
    pcf8574.digitalWrite(PinMotor, !value); 
    analogWrite(in3, 255);
    pcf8574.digitalWrite(in4, HIGH);
    delay(5000);
<<<<<<< HEAD
    String path = "HoCa/Feed";
=======
    String path = "HoCa/Feed/value";
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
    Firebase.setBool(path, false);
    pcf8574.digitalWrite(PinMotor, HIGH);
   }
