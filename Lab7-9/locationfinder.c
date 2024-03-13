void turnGyro(long power, long turnDegree);//the speed of the motors during the turn, how many degrees motorC it will turn

void drive(long nMotorRatio, long dist, long power);// the ratio of the motors, how far in centimatres to travel, how fast to travel

#define Centimetre 20.93

task main()
{

	int count = 0;
	int notblack=0;
	int dist=10;

	while (!SensorValue(sensorEV3_Touch))
	{
		setMotorSpeed(motorB, 30);
		setMotorSpeed(motorC, 30);

		if (SensorValue(sensorEV3_Color) < 40 && (notblack==1))
		{
			count++;
			displayCenteredBigTextLine(3, "Black Lines: %d", count);
			notblack=0;
		}
		if (SensorValue(sensorEV3_Color) > 40)
		{
			notblack=1;
		}

	}

	drive(0, dist, 20); // travel foward dist cm at 20 power
	turnGyro(10, 90); //power 10, turn motorC 90*

}

void turnGyro(long power, long turnDegree) //the speed of the motors during the turn, how many degrees motorC it will turn
{
	resetGyro(S3);
	while(getGyroDegrees(S3) < turnDegree)//the minus is to account for the lag
	{
		displayCenteredBigTextLine(6,"sensorEV3_Gyro:%d",getGyroDegrees(S3));//debbugging text
		setMotorSpeed(motorB,power);//motors are turning
		setMotorSpeed(motorC,-power);
	}
	setMotorSpeed(motorB,0);//stopping the motors after
	setMotorSpeed(motorC,0);

}

void drive(long nMotorRatio, long dist, long power) // the ratio of the motors, how far in centimatres to travel, how fast to travel
{
	int rotations = (Centimetre * dist);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	setMotorSyncEncoder(motorB, motorC, nMotorRatio, rotations, power);

	waitUntilMotorStop(motorC);
}
