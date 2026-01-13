#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
int buzzer = 8;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
int melody[] = {1000, 1200, 1500};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
String password = "1234";

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (!key) return;

  if (key >= '0' && key <= '9') {
    input += key;               // 숫자면 저장
    Serial.print("*");          // 화면엔 *로 표시
  }

  else if (key == '#') {        // 엔터 역할
    Serial.println();
    if (input == password) {
      Serial.println("UNLOCK!");
      
      for (int i = 0; i < 3; i++) {
      tone(10, melody[i]);
      delay(300);}
      noTone(10);
      
    } else {
      Serial.println("WRONG PASSWORD!");
      tone(10,100);
      delay(500);
      noTone(10);
    }
    input = "";                 // 입력 초기화
  }

  else if (key == '*') {        // 취소/리셋
    input = "";
    Serial.println("\nRESET");
  }
}
