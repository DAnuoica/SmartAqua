void Setting() {
  
Timer::getInstance()->initialize();

batsukien =  new WorkScheduler(500UL, catchEvent);
dieukhiennonglanh =  new WorkScheduler(1,1000UL, stopWarmerCooler);
baothucan =  new WorkScheduler(5000UL, notiFeed);
guidulieu =  new WorkScheduler(30000UL, trueTime);
hengio =  new WorkScheduler(10000UL, doSchedule);

gServo1.attach(SERVO1_PIN); 
gServo2.attach(SERVO2_PIN); 
pcf8574.pinMode(PinLED, OUTPUT);
pcf8574.pinMode(PinMotor, OUTPUT);
pcf8574.pinMode(PinCooler, OUTPUT);
pcf8574.pinMode(PinOxi, OUTPUT);
pcf8574.pinMode(PinWarmer, OUTPUT);
pinMode(in3, OUTPUT);
pcf8574.pinMode(in4, OUTPUT);  
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  pcf8574.begin();

sensors.begin(); // temp module

Wire.begin(); //
lightMeter.begin(); // Light Module

  }
