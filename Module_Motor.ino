void controlFeed(bool value) {
    pcf8574.digitalWrite(PinMotor, !value); 
    analogWrite(in3, 255);
    digitalWrite(in4, LOW);
   }
