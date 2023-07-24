// Code by Guppy, the best Arduino programmer I know!
#include <TM1638.h>

TM1638 tm(3, 2, 4);

bool relay = false;
uint8_t buttons = 0;
uint8_t oldButtons = 0;
uint8_t testCombo[8] = {0,0,0,0,0,0,0,0};
uint8_t combo[8] = {2,0,2,3,1,9,8,3};
void setup() {
  tm.reset();
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttons = tm.getButtons();
  bool buttonPressed = false;

  for (uint8_t i = 0; i < 8; i++){
    bool button = (buttons  >> i) & 1;
    bool oldButton = (oldButtons  >> i) & 1;
    if (button != oldButton){
      if(button){
        if(testCombo[i] < 9){
          testCombo[i] ++;
        }
        else{
          testCombo[i] = 0;
        }
        buttonPressed = true;
        
      }
      oldButtons |= 1 << i;;
    }
     tm.displayDig(i, testCombo[i]);
  }

  if(buttonPressed){
    bool comboMatched = true;
    for (uint8_t i = 0; i < 8; i++){
      if(combo[i] != testCombo[i]){
        comboMatched = false;
      }
    }
    if(comboMatched){
      digitalWrite(relay, HIGH);  // trigger relay
      delay(1000);                // wait for a second
      digitalWrite(relay, LOW);   // turn the relay off
    }
  }

  delay(100);

}
