#include <TM1638.h>

// define a module on data pin 3, clock pin 2 and strobe pin 4
TM1638 module(3, 2, 4);

//Declare Variables
byte buttons;
int firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit, sixthDigit, seventhDigit, eighthDigit = 0;
int firstScreen = 64;
int secondScreen = 32;
int thirdScreen = 16;
int fourthScreen = 8;
int fifthScreen = 4;
int sixthScreen = 2;
int seventhScreen = 1;
int eighthScreen = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  //module.clearDisplay();
  //Read buttons and add a digit if pressed
  buttons = module.getButtons();
  if (buttons == 1){
    Serial.print("FirstDigit Before: ");
    Serial.println(firstDigit);
    firstDigit = AddNumberToDigit(firstDigit, firstScreen);
    Serial.println("Button 1 Pressed");
    Serial.print("FirstDigit After: ");
    Serial.println(firstDigit);
  }
  if (buttons == 2){
    secondDigit = AddNumberToDigit(secondDigit, secondScreen);
    Serial.println("Button 2 Pressed");
  }
  delay (100);
}

//Function to add a number to the display
int AddNumberToDigit(int currentDigit, int displayNumber){
  Serial.print("currentDigit Before: ");
  Serial.println(currentDigit);
  ++currentDigit;
  if (currentDigit > 9) {
    currentDigit = 0;
  }
  module.setDisplayDigit(currentDigit,displayNumber,false);
  Serial.print("currentDigit After: ");
  Serial.println(currentDigit);
  return currentDigit;
}
