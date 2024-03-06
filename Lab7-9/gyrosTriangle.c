#pragma config(Sensor, S1,     light,          sensorEV3_Color)
#pragma config(Sensor, S2,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S3,     gyro,          sensorEV3_Gyro)
#pragma config(Sensor, S4,     ultraS,         sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          Left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          Right,         tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnGyro(long power, long turnDegree);//the speed of the motors during the turn, how many degrees right it will turn

void drive(long nMotorRatio, long dist, long power);// the ratio of the motors, how far in centimatres to travel, how fast to travel

#define Centimetre 20.93

task main()
{
	int button=0;// for the button presses
	int dist=15; // how far it will travel



	while (getButtonPress(buttonEnter) == 0 )//picking the distance travelled
	{
		sleep(200);
		//this is a loop for the menu including overflow
		if (getButtonPress(buttonRight))
		{
			button++;
		}

		if (getButtonPress(buttonLeft))
		{
			button--;
		}

		if (button % 3==1)
		{
			dist = 30;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}

		if (button % 3==2)
		{
			dist = 45;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}

		if (button % 3==0)
		{
			dist = 15;
			displayCenteredBigTextLine(3,"Distance: %d",dist);
		}
	}


	drive(0, dist, 20);//go foward dist cm
	turnGyro(10, 120); //turn right 120*

	drive(0, dist, 20);//go foward dist cm
	turnGyro(10, 120); //turn right 120*

	drive(0, dist, 20);//go foward dist cm
	turnGyro(10, 120); //turn right 120*


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
