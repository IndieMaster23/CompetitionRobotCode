#include <iostream>
#include "vex.h"
#include "commands.h"

bool Commands :: arcadeControlMode = true;
int Commands :: count = 0;
long Commands :: t = 0;
std::string Commands :: ctrlSeq = "";

bool Commands :: isArcadeControlMode(void)
{
  return arcadeControlMode;
}

void Commands :: buttonPressed(std::string s)
{
  std::cout << "Button pressed: " << s << "\n";
  long now = std::time(0);
  if((now - t) > 1) {
    t = now;
    ctrlSeq = "";
  }
  ctrlSeq += s;
  std::cout << "now: " << now << "\n";
  printf("ctrlSeq: %s\n", ctrlSeq.c_str());

  if(ctrlSeq == "ABL") arcadeControlMode = true;
  else if(ctrlSeq == "ABR") arcadeControlMode = false;
}

void Commands :: leftButtonPressed(void)
{
  buttonPressed("L");
}

void Commands :: rightButtonPressed(void)
{
  buttonPressed("R");
}

void Commands :: upButtonPressed(void)
{
  buttonPressed("U");
}

void Commands :: downButtonPressed(void)
{
  buttonPressed("D");
}

void Commands :: aButtonPressed(void)
{
  buttonPressed("A");
}

void Commands :: bButtonPressed(void)
{
  buttonPressed("B");
}

void Commands :: xButtonPressed(void)
{
  buttonPressed("X");
}

void Commands :: yButtonPressed(void)
{
  buttonPressed("Y");
}

void Commands :: init(const vex::controller controller)
{
  std::cout << "Initializing buttons\n";
  controller.ButtonLeft.pressed(leftButtonPressed);
  controller.ButtonRight.pressed(rightButtonPressed);
  controller.ButtonUp.pressed(upButtonPressed);
  controller.ButtonDown.pressed(downButtonPressed);
  controller.ButtonA.pressed(aButtonPressed);
  controller.ButtonB.pressed(bButtonPressed);
  controller.ButtonX.pressed(xButtonPressed);
  controller.ButtonY.pressed(yButtonPressed);
}

