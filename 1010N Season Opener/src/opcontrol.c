#include "main.h"
#include "drive.h"
#include "mobileGoalLift.h"
#include "arm.h"
#include "claw.h"
/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
	while (1) {
		delay(20);

		//drive
		leftDrive(joystickGetAnalog(1, 2));
		rightDrive(joystickGetAnalog(1, 3));

		//MG Lift
		if (joystickGetDigital(1, 5, JOY_UP)) {
			goalLift(127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)) {
			goalLift(-127);
		}
		else {
			goalLift(0);
		}
		//Arm
		if (joystickGetDigital(2, 6, JOY_UP)) {
			armLift(127);
		}
		else if (joystickGetDigital(2, 6, JOY_DOWN)){
			armLift(-127);
		}
		else {
			armLift(0);
		}
		if (joystickGetDigital(2, 5, JOY_UP)) {
			clawMove(127);
		}
		else if (joystickGetDigital(2, 5, JOY_DOWN)) {
			clawMove(-127);
		}
		else {
			clawMove(0);
		}
	}
}
