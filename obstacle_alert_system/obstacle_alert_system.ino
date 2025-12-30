void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10,LOW);
  delayMicroseconds(2);

  digitalWrite(10,HIGH);
  delayMicroseconds(10);
  digitalWrite(10,LOW);

  long duration = pulseIn(8,HIGH,25000);
  float dist = duration * 0.034 / 2;

  Serial.print(dist);
  Serial.println("cm");
  int gap;

  if(dist < 10) gap = 50;
  else if (dist < 15) gap = 120;
  else if (dist < 20) gap = 200;
  else if (dist < 30) gap = 350;
  else if (dist < 40) gap = 500;
  else
  {
    noTone(11);
    delay(100);
    return;
  }
tone(11,262);
delay(80);
noTone(11);
delay(gap);
}
