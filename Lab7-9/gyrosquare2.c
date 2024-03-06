#pragma config(Sensor, S1,     light,          sensorEV3_Color)
#pragma config(Sensor, S2,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S3,     gyro,          sensorEV3_Gyro)
#pragma config(Sensor, S4,     ultraS,         sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          Left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          Right,         tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnGyro(long power, long turnDegree);

void drive(long nMotorRatio, long dist, long power);

#define Centimetre 20.93

task main()
{
	int button=0;
	int dist=10;



	while (getButtonPress(buttonEnter) == 0 )//picking the distance travelled
	{
		sleep(200);

		if (getButtonPress(buttonRight))
		{
			button++;
		}

		if (getButtonPress(buttonLeft))
		{
			button--;
		}

		if (button % 4==1)
		{
			dist = 20;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}

		if (button % 4==2)
		{
			dist = 25;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}

		if (button % 4==3)
		{
			dist = 40;
			displayCenteredBigTextLine(3,"Distance: %d",dist);

		}

		if (button % 4==0)
		{
			dist = 10;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}
	}


	drive(0, dist, 20);
	turnGyro(10, 90);

	drive(0, dist, 20);
	turnGyro(10, 90);

	drive(0, dist, 20);
	turnGyro(10, 90);

	drive(0, dist, 20);
	turnGyro(10, 90);

}

void turnGyro(long power, long turnDegree)
{
	resetGyro(gyro);
	while(getGyroDegrees(gyro)-1<turnDegree-3)//the minus is to account for the lag
	{
		displayCenteredBigTextLine(6,"Gyro:%d",getGyroDegrees(gyro));//debbugging text
		setMotorSpeed(Left,power);//motors are turning
		setMotorSpeed(Right,-power);
	}
	setMotorSpeed(Left,0);//stopping the motors after
	setMotorSpeed(Right,0);

}

void drive(long nMotorRatio, long dist, long power)
{
	int rotations = (Centimetre * dist);

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);

	setMotorSyncEncoder(Left, Right, nMotorRatio, rotations, power);

	waitUntilMotorStop(Right);
}