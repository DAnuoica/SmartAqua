/*
 * Kết nối:
 *     red       VCC  ---- 5V (Arduino)
 *     black     GND  ---- GND (Arduino)
 *     yellow    DATA ----  2  (Arduino)  16 (wemos)
 *    
 *    more details: circuit ds18b20
 */
 
int getCurrentTemp() 
{ 
 sensors.requestTemperatures();
 Serial.println(sensors.getTempCByIndex(0));
 return (int)sensors.getTempCByIndex(0);
} 
