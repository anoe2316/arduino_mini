int buzzer = 8;
int melody[] = {262, 294, 330, 349, 392, 440, 494};

void setup() {}

void loop() {
  for (int i = 0; i < 7; i++) {
    tone(buzzer, melody[i]);
    delay(300);
    noTone(buzzer);
    delay(50);
  }
  delay(2000);
}
