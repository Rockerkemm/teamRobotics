#pragma config(Motor,  motorB,          Left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          Right,         tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveRobot(long nMotorRatio, long time, long power)
{

	setMotorSyncTime(Left, Right, nMotorRatio, time, power);
	sleep(1000);
}

/*
void randomDirection()
{
	int Direction = random(1);

	if (Direction == 1)
	{
		setMotorSpeed(Left, -50);
		setMotorSpeed(Right, 50);
		sleep(380);
	}
	else
	{
		setMotorSpeed(Left, 50);
		setMotorSpeed(Right, -50);
		sleep(380);
	}
}
*/
task main()
{
	moveRobot(0, 1000, 50);
	moveRobot(100, 432, 50);
	moveRobot(0, 1000, 50);
	moveRobot(100, 432, 50);
	moveRobot(0, 1000, 50);
	moveRobot(100, 432, 50);
	moveRobot(0, 1000, 50);
	moveRobot(100, 432, 50);
}
