void switchLed(bool value) {
<<<<<<< HEAD
  pcf8574.digitalWrite(PinLed, !value);
=======
  pcf8574.digitalWrite(PinLED, !value);
>>>>>>> c0b460c1c799114d64f17a9e218ee143fea66a8a
  }
void switchFeed(bool value) {
   if(value == true) controlFeed(value);
  }
void switchCooler(bool value) {
   pcf8574.digitalWrite(PinCooler, !value); 
  }
void switchOxi(bool value) {
   pcf8574.digitalWrite(PinOxi, !value); 
  }

void switchWarmer(bool value) {
  pcf8574.digitalWrite(PinWarmer, !value); 
  }
void switchPurifier(bool value) {
  pcf8574.digitalWrite(PinWarmer, !value); 
  }
