#include <Keyboard.h>;

const int  buttonPin1 = 2;    // the pin that the pushbutton is attached to


class Button {
private:
 int buttonPin;
 String number;
 int buttonState;         // current state of the button
 int lastbuttonState;     // previous state of the button
 
public:
 Button(int, String);
 void checkButton();
};

Button::Button(int buttonPin, String number)
{
 this->buttonPin = buttonPin;
 this->number = number;
 pinMode(buttonPin, INPUT_PULLUP);
}

// Find the number of beats the button has been down for. Function can compute max. 8 sec down before rolling over.
void Button::checkButton()
{
  buttonState = digitalRead(this->buttonPin);

  // compare the buttonState1 to its previous state
  if (buttonState != lastbuttonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button
      // wend from off to on:
 
      Serial.println("on");
      Keyboard.print(String(this->number));            // same thing as a quoted character
      delay(100);
    } 
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
 
      Serial.println("off");
      if(this->number == "a")
        Keyboard.print("s");            // same thing as a quoted character
      else if(this->number == "d")
        Keyboard.print("f");            // same thing as a quoted character
      else if(this->number == "g")
        Keyboard.print("h");            // same thing as a quoted character
      else
        Keyboard.print(String(this->number + 1));            // same thing as a quoted character

       
      delay(100);
    } 
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastbuttonState = buttonState;
}

Button nummer1(1,"0");
Button nummer2(2,"a");


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Keyboard.begin();
}

void loop() {
  nummer1.checkButton();
  nummer2.checkButton();
}
