#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(11);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 10; i <= 110; i++)
  {
      myservo.write(i);
      delay(20);
  }
  
delay(3000);

for(int i = 110; i >= 10; i--)
  {
      myservo.write(i);
      delay(20);
  }
  delay(3000);
}
