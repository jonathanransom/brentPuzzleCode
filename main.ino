#include <TM1638.h>
// https://github.com/rjbatista/tm1638-library

// define a module on data pin 3, clock pin 2 and strobe pin 4
TM1638 module(3, 2, 4);
// Declare Variables
byte buttons;
int firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit, sixthDigit, seventhDigit, eighthDigit = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  // module.clearDisplay();
  // Read buttons and add a digit if pressed
  buttons = module.getButtons();
  if (buttons == 1){
    firstDigit = AddNumberToDigit(firstDigit, 0);
    Serial.println("Button 1 Pressed");
  }
  if (buttons == 2){
    secondDigit = AddNumberToDigit(secondDigit, 0);
    Serial.println("Button 2 Pressed");
  }
  delay (100);
}

// Function to add a number to the display
int AddNumberToDigit(int currentDigit, int displayNumber){
  Serial.print("currentDigit Before: ");
  Serial.println(currentDigit);
  currentDigit = currentDigit++;
  if (currentDigit > 9) {
    currentDigit = 0;
  }
  module.setDisplayToDecNumber(displayNumber,currentDigit,false);
  Serial.print("currentDigit After: ");
  Serial.println(currentDigit);
  return currentDigit;
}
