enum State{
  GREEN,
  YELLOW,
  RED,
};
const int green = 8;
const int red = 9;
const int yellow = 10;
State currentState = GREEN;
unsigned long previousMillis = 0;
const unsigned long interval = 5000;


void setup() {
  // put your setup code here, to run once:
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(currentState){
    case GREEN: if(millis() - previousMillis > interval){
    previousMillis = millis();
    currentState = YELLOW;
  }break;
  case YELLOW: if(millis() - previousMillis > 3000)
  {
    previousMillis = millis();
    currentState = RED;
  }break;
  case RED: if(millis() - previousMillis > interval){
    previousMillis = millis();
    currentState = GREEN;
  }break;
  }
  



switch(currentState){
  case GREEN: 
        digitalWrite(red,LOW);
        digitalWrite(green,HIGH);break;
  case YELLOW:
        digitalWrite(green,LOW);
        digitalWrite(yellow,HIGH);break;
  case RED:
        digitalWrite(yellow,LOW);
        digitalWrite(red,HIGH);break;
}
}
