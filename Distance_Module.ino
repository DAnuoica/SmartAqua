/*
* Kết nối:
            HCSR04                          Arduino             wemos        code    
            VCC                               5V  
            GND                               GND
            TRIG                              8                 2             16    p0
            ECHO                              7                 5             14    p1

   Nạp code mở Serial Monitor chọn No line ending, baud 9600.
   */
void notiFeed() {
  if(getDistance() >8) {
  Serial.println("Het thuc an");
  delay(50);
  }
}
int getDistance()
{
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);    
    /* In kết quả ra Serial Monitor */
 //   Serial.print(distance);
 //   Serial.println("cm");
    return distance;
}
