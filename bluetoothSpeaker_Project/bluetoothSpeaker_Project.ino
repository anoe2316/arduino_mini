#include <AltSoftSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

AltSoftSerial dfSerial;      // DFPlayer (8,9 고정)
SoftwareSerial bt(2, 3);     // HC-05 (RX, TX)

DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  dfSerial.begin(9600);
  bt.begin(9600);

  if (!player.begin(dfSerial)) {
    Serial.println("DFPlayer 연결 실패");
    while (1);
  }

  Serial.println("DFPlayer OK");
  player.volume(20);
}

void loop() {
  if (bt.available() > 0) {
    char message = bt.read();

    Serial.print("받은 값: ");
    Serial.println(message);

    switch (message) {
      case '1':
        player.play(1);
        break;

      case '2':
        player.pause();
        break;

      case '3':
        player.next();
        break;

      case '4':
        player.previous();
        break;
    }
  }
}
