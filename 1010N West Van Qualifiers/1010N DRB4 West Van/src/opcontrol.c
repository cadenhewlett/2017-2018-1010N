#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"
#include "intake.h"
#include "chainbar.h"
#include "mogo.h"
#include "arm.h"

#define startHeight 300
int height = startHeight;

void operatorControl() {

	gyroReset(gyro);
	analogCalibrate(ARMPOT);
	analogCalibrate(CHAINPOT);
	analogCalibrate(MOGOPOT);

	while (1) {

		TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

		//***********************
		//       Drive
		//***********************

		int Y1 = 0; //Y-Axis on Arcade
		int X1 = 0; //X-Axis on Arcade
		int deadZone = 10; //Deadzone Value // Was 20

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

		bool armStick = joystickGetAnalog(2,2);
		float armKp = 0.3;
		float armKd = 3;
		int armTarget;
		int armSpeed;
		int armError;
		int armErrorDiff;
		int armErrorLast;
		float armP;
		float armD;

		if(joystickGetAnalog(2,2)){
			moveArm(joystickGetAnalog(2,2));
			armTarget = analogRead(ARMPOT);
		}
		else if(joystickGetDigital(2,8,JOY_DOWN)){
			armError = 300 - analogRead(ARMPOT);
			armSpeed = armError * armKp;
			moveArm(armSpeed);
		}
		else if(armStick == 0){
			armError = armTarget - analogRead(ARMPOT);
			armP = armError * armKp;
			armErrorDiff = armError - armErrorLast;
			armErrorLast = armError;
			armD = armKd * armErrorDiff;
			armSpeed = armP + armD;
			moveArm(armSpeed);
		}
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
			moveMogo(-127);
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
			moveIntake(0);
		}

		//***********************
		//     Four BAR
		//***********************

		bool barUp = joystickGetDigital(2,5,JOY_UP);
		bool barDown = joystickGetDigital(2,5,JOY_DOWN);
		float barGain = 0.3;
		int barError;
		int barSpeed;

		if(barUp == 1 && barDown == 0){
			moveChainBar(127);
		}
		else if(barUp == 0 && barDown == 1){
			moveChainBar(-127);
		}
		else if(barUp == 1 && barDown == 1){
			barError = 1800 - analogRead(CHAINPOT);
			barSpeed = barError * barGain;
			moveChainBar(barSpeed);
		}
		else{
			moveChainBar(0);
		}

		delay(20);
	}
}
