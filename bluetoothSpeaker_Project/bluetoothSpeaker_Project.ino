#include <AltSoftSerial.h>
#include <DFRobotDFPlayerMini.h>

AltSoftSerial mySerial;   
DFRobotDFPlayerMini player;

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

  delay(1500); 

  if (!player.begin(mySerial)) {
    
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
