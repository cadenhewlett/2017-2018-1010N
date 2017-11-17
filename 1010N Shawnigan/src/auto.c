#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mogo.h"
#include "arm.h"

#define UP -1
#define DOWN 1
#define FORWARD 1
#define BACK -1
#define RIGHT 1
#define LEFT -1

void skills() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA);
  moveIntake(-40);
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 3000, 1.5, 6);
  moveMogo(-127);
  delay(500);
  drive(FORWARD,800);
  delay(200);
  moveMogo(127);
  delay(1500);
  moveMogo(0);
  turn(LEFT, 200, 2000, 1.5, 3);
  moveIntake(127);
  drive(FORWARD,750);
  moveIntake(0);
  turn(LEFT, 110, 1500, 1.5, 3);
  drive(FORWARD, 400);//WAS 275
  turn(RIGHT, 110, 1500, 1.5, 3);
  moveDrive(127,127);
  delay(2000);
  moveDrive(0,0);
  moveMogo(-127);
  delay(1500);
  moveDrive(-127,-127);
  delay(100);
  moveMogo(127);
  delay(400);
  moveMogo(0);
  delay(500);
  turn(LEFT,110,1500,1.5,3);
  drive(FORWARD, 300);
  turn(LEFT,110,1500,1.5,3);
  stopEverything();
}

void mobileleftred() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA); //Reset Encoder
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveMogo(127); //Pick up mobile goal
  delay(1500); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  moveIntake(127); //Let go of cone
  delay(1000); //Timeout rollers
  moveIntake(0); //Stop intake
  turn(RIGHT,210,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(RIGHT,55,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(450); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void mobilerightblue() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA); //Reset Encoder
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveMogo(127); //Pick up mobile goal
  delay(1500); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  moveIntake(127); //Let go of cone
  delay(1000); //Timeout rollers
  moveIntake(0); //Stop intake
  turn(LEFT,225,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(LEFT,55,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(450); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void mobilerightred() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA); //Reset Encoder
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveMogo(127); //Pick up mobile goal
  delay(1500); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  moveIntake(127); //Let go of cone
  delay(1000); //Timeout rollers
  moveIntake(0); //Stop intake
  turn(RIGHT,210,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(RIGHT,55,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(450); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void mobileleftblue() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA); //Reset Encoder
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127); //Mogo Down
  drive(FORWARD, 1300); //Drive Forward Towards MobileGoal
  moveMogo(0); //Mogo Stop
  delay(300); //Timeout break
  moveMogo(127); //Pick up mobile goal
  delay(1500); //Timeout pick up
  moveMogo(0); //Stop mobile goal
  moveIntake(127); //Let go of cone
  delay(1000); //Timeout rollers
  moveIntake(0); //Stop intake
  turn(RIGHT,210,2700,1.5,4); //Turn right 210 degrees towards stationary goal
  drive(FORWARD, 1000); //Drive back to start
  turn(RIGHT,55,700,1.5,3); //Turn right towards scoring zones
  moveDrive(127,127); //Drive into 10 point zone
  delay(450); //Timeout drive over pipe
  moveDrive(0,0); //Stop drive
  moveMogo(-127); //Drop mobile goal
  delay(1300); //Timeout drop mobile goal
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
}

void stationarygoal() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA);
  moveIntake(-40);
  arm(UP, 15, 500, 1.5, 3); //ShakeArm
  arm(DOWN, 15, 500, 1.5, 3); //ShakeArm
  barup(UP, 2500, 3000, 1.5, 6);
  arm(UP, 100, 1500,1.5,3);
  drive(FORWARD,525);
  delay(300);
  arm(DOWN,20,2000,1.5,3);
  moveIntake(127);
  delay(100);
  arm(UP, 40, 2000,1.5,3);
  drive(BACK,250);
  moveIntake(-127);
  delay(200);
  turn(RIGHT,100,1500,1.5,3);
  drive(FORWARD,25);
  moveArm(127);
  delay(1000);
  moveArm(0);
  bardown(DOWN, 670, 1000, 1.5, 3);
}

void pointred() {
  encoderReset(encoderL);
  encoderReset(encoderR);
  encoderReset(encoderA);
  moveIntake(-40); //Hold PreLoad until Mobile Goal
  barup(UP, 2500, 1500, 1.5, 9); //Arm Up to open way for Mogo and Intake
  moveMogo(-127);
  drive(FORWARD, 1400);
  moveMogo(0);
  delay(300);
  moveMogo(127);
  delay(1300);
  moveMogo(0);
  moveIntake(127);
  delay(500);
  moveIntake(0);
  turn(RIGHT,210,2700,1.5,3);// 210 before
  drive(FORWARD, 1000);



  moveDrive(127,127);
  delay(1000);
  moveDrive(0,0);
  moveMogo(-127);
  delay(1300);
  moveDrive(-127,-127);
  delay(200);
  moveMogo(127);
  delay(400);
  stopEverything();
  barup(UP, 2500, 3000, 1.5, 6);
}

void pointblue() {

}

void noauto() {

}

void autonomous(){

switch(myauto){

    case -1:
      noauto();
    break;

    case 0:
      stationarygoal();
      break;

    case 1:
    mobileleftred();
    break;

    case 2:
    mobilerightblue();
    break;

    case 3:
    mobilerightred();
    break;

    case 4:
    mobileleftblue();
    break;

    case 5:
    stationarygoal();
    break;

    case 6:
    pointred();
    break;

    case 7:
    pointblue();
    break;

 }
}
