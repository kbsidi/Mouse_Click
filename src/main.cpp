#include <Arduino.h>

#include "Mouse.h"

// set pin numbers for the five buttons:
#if 0
const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
#endif
const int mouseButton = 10;

int range = 5;           // output range of X or Y movement; affects movement speed
int responseDelay = 10;  // response delay of the mouse, in ms


void setup() {
  // initialize the buttons' inputs:
  #if 0
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  #endif
  pinMode(mouseButton, INPUT_PULLUP);
  // initialize mouse control:
  Mouse.begin();
}

void loop() {
  // read the buttons:
  #if 0
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  int rightState = digitalRead(rightButton);
  int leftState = digitalRead(leftButton);
  #endif
  int clickState = digitalRead(mouseButton);

  // calculate the movement distance based on the button states:
#if 0
  int xDistance = (leftState - rightState) * range;
  int yDistance = (upState - downState) * range;

  // if X or Y is non-zero, move:
  if ((xDistance != 0) || (yDistance != 0)) {
    Mouse.move(xDistance, yDistance, 0);
  }

#endif

  // if the mouse button is pressed:
  if (clickState == LOW) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
}
