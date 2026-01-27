#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  LCD.begin(16,2);
  LCD.print("Distance:");

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,LOW);
  delayMicroseconds(2);

  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);

  long duration = pulseIn(8,HIGH,25000);
  float dist = duration * 0.034 / 2;

  LCD.setCursor(0,1);
  LCD.print("      "); // clear area
  LCD.setCursor(0,1);
  LCD.print(dist,1);
  LCD.print(" cm");
  int gap;

  if(dist < 10) gap = 50; 
  else if (dist < 15) gap = 120; 
  else if (dist < 20) gap = 200; 
  else if (dist < 30) gap = 350;
  else if (dist < 40) gap = 500;
  else
  {
    noTone(13);
    delay(100);
    
    return;
  }

tone(13,262);
delay(80);
noTone(13);
delay(gap);

}
