#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "fourbar.h"
#include "mogo.h"
#include "arm.h"

void operatorControl() {

	encoderReset(encoderA);
	gyroReset(gyro);

	while (1) {

		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//***********************
		//       Drive
		//***********************

		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 5; //Deadzone Value

		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int leftStickHorizontal = joystickGetAnalog(1, 1); //Joystick command for horizontal movement

		if (abs (leftStickVertical) > deadZone) {
			Y1 = leftStickVertical; }
		else {
			Y1 = 0;
		}
		if (abs (leftStickHorizontal) > deadZone) {
			X1 = leftStickHorizontal; }
		else {
			X1 = 0;
		}

		//Left Drive
		motorSet(DRIVE_LF, Y1 + X1);//Left Front
		motorSet(DRIVE_LB, Y1 + X1);//Left Back

		//Right Drive
		motorSet(DRIVE_RF, -Y1 + X1);//Right Front
		motorSet(DRIVE_RB, -Y1 + X1);//Right Back

		//***********************
		//        Arm
		//***********************
		int arm_targetValue;
		if (joystickGetDigital(1, 6, JOY_UP)){
			moveArm(-127);
			arm_targetValue = (encoderGet(encoderA));
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			moveArm(127);
			arm_targetValue = (encoderGet(encoderA));
		}
		/*else if(joystickGetDigital(1, 6, JOY_UP) == 0 && joystickGetDigital(1, 6, JOY_DOWN) == 0) {

			int arm_gain = 1.5; //Old P Loop
			int arm_error = arm_targetValue - encoderGet(encoderA);
			int arm_speed = arm_error * arm_gain;
			motorCap(arm_speed,127);
			moveArm(arm_speed);
			if(encoderGet(encoderA)>-50){
			armPID(arm_targetValue, 1.2, 9);
		} //New PID Loop
			else{moveArm(0);}

	}*/
		else{
			moveArm(0);
		}

		//***********************
		//   Mobile Goal Lift
		//***********************

		if (joystickGetDigital(1, 5, JOY_UP)){
			moveMogo(127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			moveMogo(-100);
		}
		else {
			moveMogo(0);
		}

		//***********************
		//       Intake
		//***********************

		if (joystickGetDigital(2, 6, JOY_UP)){
			moveIntake(127);
		}
		else if (joystickGetDigital(2, 6, JOY_DOWN)){
			moveIntake(-127);
		}
		else {
			moveIntake(-30);
			//moveIntake(0);
		}

		//***********************
		//     Four BAR
		//***********************

		if (joystickGetDigital(2, 5, JOY_DOWN)){
			moveFourBar(-127);
		}
		else if (joystickGetDigital(2, 5, JOY_UP)) {
			moveFourBar(127);
		}
		else if (joystickGetDigital(2,8,JOY_RIGHT)){
			int bar_gain = 1.05;
			int bar_error = 1250 - analogRead(1);
			int bar_speed = bar_error * bar_gain;
			motorCap(bar_speed, 10);
			moveFourBar(bar_speed);
			}
			else if (joystickGetDigital(2,8,JOY_UP)){
				int bar_gain = 1.2;
				int bar_error = 2750 - analogRead(1);
				int bar_speed = bar_error * bar_gain;
				motorCap(bar_speed, 10);
				moveFourBar(bar_speed);
				}
		else{
			moveFourBar(0);
		}

		delay(20);
	}
}
