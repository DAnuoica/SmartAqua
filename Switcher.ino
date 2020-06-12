void switchLed(bool value) {
  pcf8574.digitalWrite(PinLED, !value);
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
