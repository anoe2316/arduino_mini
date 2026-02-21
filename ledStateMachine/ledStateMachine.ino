enum State{
  ON,
  OFF,
  BLINK,
};
State currentState = OFF;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool currentButtonState;
unsigned long previousMillis = 0;
const unsigned long delayInterval = 500;
bool ledState = LOW;



void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(8,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  bool reading = digitalRead(8);
  if(reading != lastButtonState){
    lastDebounceTime = millis();
      }
    if((millis() - lastDebounceTime) >= debounceDelay){
      if(reading != currentButtonState){
        currentButtonState = reading;

        if(currentButtonState == LOW)
        {
          switch(currentState)
          {
            case OFF: currentState = ON;break;
            case ON: currentState = BLINK;break;
            case BLINK: currentState = OFF;break;
          }
        }
      }
    }
    lastButtonState = reading;
    switch(currentState)
    {
      case OFF: digitalWrite(9,LOW);break;
      case ON: digitalWrite(9,HIGH);break;
      case BLINK: if((millis() - previousMillis) >= delayInterval)
      {
        previousMillis = millis();
        ledState = !ledState;
        digitalWrite(9,ledState);
      }break;

    }


}
