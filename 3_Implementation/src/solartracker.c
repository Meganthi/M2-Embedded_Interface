#include <Servo.h>

void setup() 
{
  myservo.attach(11); 
  Serial.begin(9600);
  myservo.write(pos);   
}
void loop() 
{
  val1 = analogRead(ldr1);            
  val2 = analogRead(ldr2);
  val1 = map(val1, 0, 1023, 0, 180);     
  val2 = map(val2, 0, 1023, 0, 180);     
  if(val1 > (val2+50))
  {    
    if(pos<180)
     pos=pos+1;
    myservo.write(pos);
    Serial.println("backward");         
    delay(10);         
  }
  else if(val2 > (val1+50))
  {
    if(pos>0)
     pos=pos-1;
    myservo.write(pos);
    Serial.println("forward");         
    delay(10); 
  }
                     
}
