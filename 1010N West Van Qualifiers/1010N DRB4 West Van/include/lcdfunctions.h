#ifndef LCDFUNCTIONS_H_
#define LCDFUNCTIONS_H_

#include "main.h"

void disablelcd(void*ignore); //LCD Task for when robot is disabled
TaskHandle disablelcd_task;

void opcontrollcd(void*ignore); //LCD Task for when robot is in driver control
TaskHandle opcontrollcd_task;

void autolcd(void*ignore); //LCD Task for when robot is in autonomous
TaskHandle autolcd_task;

extern int myauto;

#endif
