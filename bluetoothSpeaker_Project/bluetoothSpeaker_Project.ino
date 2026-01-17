#include <AltSoftSerial.h>
#include <DFRobotDFPlayerMini.h>

AltSoftSerial mySerial;   // RX=8, TX=9 (Uno 고정)
DFRobotDFPlayerMini player;

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

  delay(1500); // ★ DFPlayer 부팅 대기 (이게 핵심)

  if (!player.begin(mySerial)) {
    // 실패하면 LED 빠르게 깜빡
    while (1) {
      digitalWrite(13, HIGH); delay(200);
      digitalWrite(13, LOW);  delay(200);
    }
  }

  player.volume(20);
}

void loop() {
  if (Serial.available() > 0) {
    char message = Serial.read();

    // 들어오면 LED 한 번 깜빡
    digitalWrite(13, HIGH); delay(80);
    digitalWrite(13, LOW);

    switch (message) {
      case '1': player.play(1); break;
      case '2': player.pause(); break;
      case '3': player.next(); break;
      case '4': player.previous(); break;
    }
  }
}
