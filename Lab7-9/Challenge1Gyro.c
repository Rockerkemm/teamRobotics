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

	while (!SensorValue(touch))//while theres not touch go foward
	{
		setMotorSpeed(Left, 50);
		setMotorSpeed(Right, 50);
	}
	setMotorSpeed(Left, 0); //stop
	setMotorSpeed(Right, 0);

	//start of the script
	drive(0, 10, -50);//go foward 10 cm
	sleep(200);
	turnGyro(20, 270); //turn right 270*


		while (!SensorValue(touch))
	{
		setMotorSpeed(Left, 50);
		setMotorSpeed(Right, 50);
	}
	setMotorSpeed(Left, 0);
	setMotorSpeed(Right, 0);
	drive(0, 10, -50); //foward 10cm
	sleep(200);
	turnGyro(20, 270); //turn right 270*

		while (!SensorValue(touch))
	{
		setMotorSpeed(Left, 50);
		setMotorSpeed(Right, 50);
	}
	setMotorSpeed(Left, 0);//stop
	setMotorSpeed(Right, 0);
	drive(0, 10, -50);//foward 10cm
	sleep(200);
	turnGyro(20, 270);//turn right 270*

	drive(0, 20, 50);
	turnGyro(20, 270);
	}

void turnGyro(long power, long turnDegree)//the speed of the motors during the turn, how many degrees right it will turn
{
	resetGyro(gyro);
	while(getGyroDegrees(gyro)-1<turnDegree-8)//the minus is to account for the lag
	{
		displayCenteredBigTextLine(6,"Gyro:%d",getGyroDegrees(gyro));//debbugging text
		setMotorSpeed(Left,power);//motors are turning
		setMotorSpeed(Right,-power);
	}
	setMotorSpeed(Left,0);//stopping the motors after
	setMotorSpeed(Right,0);

}

void drive(long nMotorRatio, long dist, long power)// the ratio of the motors, how far in centimatres to travel, how fast to travel

{
	int rotations = (Centimetre * dist);

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);

	setMotorSyncEncoder(Left, Right, nMotorRatio, rotations, power);

	waitUntilMotorStop(Right);
}