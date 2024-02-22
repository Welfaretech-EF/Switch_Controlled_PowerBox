#include "RCSwitch.h"
RCSwitch mySwitch = RCSwitch();

// The codes for turning the RF receiving device on and off.
const char* ON_BITS = "000001010101010100110011";
const char* OFF_BITS = "000001010101010100110011";

long lastBuzz = 0;
bool ison = false;
long debugMS = 0;

// Set to true to enable demo mode (automatically toggling between on and off)
bool demo = false;

void setup() {

  // Enable serial 
  Serial.begin(9600);

  // Set pin and pulselength for RF transmitter
  mySwitch.enableTransmit(2);
  mySwitch.setPulseLength(160);

  // Set pin for buzzer
  pinMode(3, INPUT_PULLUP);
  if(!demo){
    attachInterrupt(digitalPinToInterrupt(3), buzz, FALLING);
  }

  // Set pin for mode-button
  pinMode(4, INPUT_PULLUP);
}

void buzz(){
  if(millis()-lastBuzz>1000){
    bool hold = digitalRead(4)==LOW;
    if(!hold){
      Serial.println("Buzz");
      ison = !ison;
    }
  }
  lastBuzz = millis();
}

void loop() {
  bool down = digitalRead(3)==LOW;
  bool hold = digitalRead(4)==LOW;
  if(down){
    if(hold){
      Serial.println("11");
    }
    else{
      Serial.println("10");
    }
  }
  else{
    if(hold){
      Serial.println("01");
    }
    else{
      Serial.println("00");
    }
  }
  // If debug is enabled, toggle between active/inactive every 5 seconds
  if(demo){
    if(millis()-debugMS>5000)
    {
      debugMS = millis();
      ison = !ison;
    }
  }
  else{
    if(millis()>1000 && hold){
      ison = down;
    }
  }
  sendrf();
  delay(200);
}

void sendrf(){
  if(ison){
    on();
  }else{
    off();
  }
}

void on()
{
  Serial.println("On");
  mySwitch.send(ON_BITS);
}
void off()
{
  Serial.println("Off");
  mySwitch.send(OFF_BITS);
}
