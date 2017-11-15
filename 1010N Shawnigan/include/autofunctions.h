#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

void motorCap(int what, int speed); //Motor Cap

void drive(int direction, int target); //Autonomous Drive Function

void turn(int direction, int targetTurn, int timeout, float kp, float kd); //Autonomous Turn Function

void armPID(int targetValue, float kp, float kd); //ArmPID for OpControl

void arm(int direction, int targetValue, int timeout, float kp, float kd);//ArmPID for Autonomous

void bar(int direction, int targetValue, int timeout, float kp, float kd);

void mogo(int direction, int timeout);

void intake(int direction, int delay);

#endif
