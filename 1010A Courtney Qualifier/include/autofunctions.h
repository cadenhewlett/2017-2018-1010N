#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

void stopEverything(); //Fucntion to Stop Everything

void motorCap(int what, int speed); //Motor Cap

void drive(int direction, int target); //Autonomous Drive Function

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function

void armPID(int targetValue, float kp, float kd); //ArmPID for OpControl

void arm(int direction, int targetValue, int timeout, float kp, float kd); //ArmPID for Autonomous

void mogoIn(int timeout); //Mobile Goal In

void mogoOut(int timeout); //Mobile Goal Out

void mogoScore();

void chainup(int targetValue, int timeout, float kp, float kd); //FourBarPID UP for Autonomous

void chaindown(int targetValue, int timeout, float kp, float kd); //FourBarPID DOWN for Autonomous

void intakeOpen(); //Open Claw

void intakeClose();

void intakeStay();

void intakeHold();

void preLoads();

void conePreset();

#endif
