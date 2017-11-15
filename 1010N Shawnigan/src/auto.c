#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mogo.h"

#define UP -1
#define DOWN 1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

void skills() {
}

void mobileleftred() {
  moveIntake(-30); //Hold PreLoad until Mobile Goal
  arm(UP, 60, 3000, 1.5, 6); //Arm Up to open way for Mogo and Intake
  moveMogo(-127);
  drive(FORWARD, 1300);
  stopEverything();
  arm(DOWN,20 , 2000 , 1.5, 9);
  moveIntake(127);
  arm(UP,60,3000,1.5,6);
  moveMogo(127);
  delay(2000);
  moveMogo(0);
  moveIntake(0);
  turn(RIGHT,180,5000,1.5,9);
  drive(FORWARD, 1000);
  turn(RIGHT,45,5000,1.5,9);
  moveDrive(127,127);
  delay(400);
  moveDrive(0,0);
  moveIntake(-127);
  delay(1500);
  moveDrive(-127,-127);
  delay(100);
  moveIntake(127);
  delay(400);
  stopEverything();
  bar(UP, 2500, 3000, 1.5, 6);
}

void mobileblue() {

}

void pointblue() {

}

void cuberight() {

}

void drivef() {

}

void backsandpright() {

}

void backsandpleft() {

}

void noauto() {

}

void autonomous() {

switch(myauto){

    case -1:
      mobileleftred();
    break;

    case 0:
      mobileleftred();
    break;

    case 1:
    mobileleftred();
    break;

    case 2:

    break;

    case 3:

    break;

    case 4:

    break;

    case 5:

    break;

    case 6:

    break;

    case 7:

    break;

 }
}
