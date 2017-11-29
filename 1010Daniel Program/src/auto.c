
#include "main.h"

#define FORWARD 1
#define BACK 1
#define LEFT 1
#define RIGHT 1
#define UP 1
#define DOWN 1

void drive(int direction, int delay){
  setMotor(DRIVE_RB, 127*direction);
  setMotor(DRIVE_RF, 127*direction);
  setMotor(DRIVE_LB, 127*direction);
  setMotor(DRIVE_LF, 127*direction);
  delay(delay);
  setMotor(DRIVE_RB, 0);
  setMotor(DRIVE_RF, 0);
  setMotor(DRIVE_LB, 0);
  setMotor(DRIVE_LF, 0);
}

void mogo(int direction, int delay){
  setMotor(MOGO, 127*direction);
  delay(delay);
  setMotor(MOGO, 0);
}

void turn(int direction, int delay){
  setMotor(DRIVE_RB, 127*direction);
  setMotor(DRIVE_RF, 127*direction);
  setMotor(DRIVE_LB, (-127)*direction);
  setMotor(DRIVE_LF, (-127)*direction);
  delay(delay);
  setMotor(DRIVE_RB, 0);
  setMotor(DRIVE_RF, 0);
  setMotor(DRIVE_LB, 0);
  setMotor(DRIVE_LF, 0);
}

void autonomous() {
}
