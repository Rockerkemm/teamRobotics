void turnGyro(long power, long turnDegree);//the speed of the motors during the turn, how many degrees motorC it will turn

void drive(long nMotorRatio, long dist, long power);// the ratio of the motors, how far in centimatres to travel, how fast to travel


#define Centimetre 20.93 //assigning symbolic names

task main()
{
	//assigning variables
	int notblack=0;
	int locX=6;
	int locY=1;
	int destX=5;
	int destY=5;
	int direction = 2;
	
	//assigning sensor types
	SensorType[2]=sensorEV3_Color;
	
	displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
	
	setMotorSpeed(1, 100);
	setMotorSpeed(2, 100);

	//if the location starts at 1, it will add another one to account the outside the box detection
	if (locX == 1)
	{
		locX--;
	}
	
	while (locX < destX)
		
	{
		if (SensorValue[2] < 40 && (notblack==1))
		{
			locX++;
			displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
			notblack=0;
		}
		if (SensorValue[2] > 40)
		{
			notblack=1;
		}
	}
	//if the location starts at 1, it will add another one to account the outside the box detection
	if (locX == 1)
	{
		locX++;
	}
	
	while (locX > destX)
		
	{
		//senses for whether it has passed a black line, if so take away or add value
		while (direction < 4)
		{
			turnGyro(40,88);
			direction++;
		}
		
		setMotorSpeed(1, 100);
		setMotorSpeed(2, 100);		
		
		if (SensorValue[2] < 40 && (notblack==1))
		{	
			locX--;
			displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
			notblack=0;
		}
		if (SensorValue[2] > 40)
		{
			notblack=1;
		}
	}
	
	
	
	setMotorSpeed(1, 100);
	setMotorSpeed(2, 100);
	
	while (locX > destX)
		
	{
		//senses for whether it has passed a black line, if so take away or add value
		if (SensorValue[2] < 40 && (notblack==1))
		{	
			locX--;
			displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
			notblack=0;
		}
		if (SensorValue[2] > 40)
		{
			notblack=1;
		}
	}
	
	//change the direction value of the robot depending on the direction its facing
	if(locY<destY && direction==2)
	{
		turnGyro(40,266);
		locY--;
	}
	else if(locY>destY && direction==2)
	{
		turnGyro(40,90);
		locY++;
	}
	
	else if(locY<destY && direction==4)
	{
		turnGyro(40,87);
		locY--;
	}
	else if(locY>destY && direction==4)
	{
		turnGyro(40,268);
		locY++;
	}
	
	setMotorSpeed(1, 100);
	setMotorSpeed(2, 100);
	
	while(locY<destY) //if destination above
	{
		//senses for whether it has passed a black line, if so take away or add value
		if (SensorValue[2] < 40 && (notblack==1))
		{
			locY++;
			displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
			notblack=0;
		}
		if (SensorValue[2] > 40)
		{
			notblack=1;
		}
	}
	
	while(locY>destY) //if destination below
	{
		//senses for whether it has passed a black line, if so take away or add value
		if (SensorValue[2] < 40 && (notblack==1))
		{
			locY--;
			displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
			notblack=0;
		}
		if (SensorValue[2] > 40)
		{
			notblack=1;
		}
	}
	
	
}

void turnGyro(long power, long turnDegree) //the speed of the motors during the turn, how many degrees motorC it will turn
{	
	SensorType[3]= sensorEV3_Gyro;
	resetGyro(3);
	while(getGyroDegrees(3) < turnDegree)//the minus is to account for the lag
	{
		setMotorSpeed(1,power);//motors are turning
		setMotorSpeed(2,-power);
	}
	setMotorSpeed(1,0);//stopping the motors after
	setMotorSpeed(2,0);
	
}

void drive(long nMotorRatio, long dist, long power) // the ratio of the motors, how far in centimatres to travel, how fast to travel
{
	int rotations = (Centimetre * dist);
	
	resetMotorEncoder(1);	 //reset both motor encoders 
	resetMotorEncoder(2);
	
	setMotorSyncEncoder(1, 2, nMotorRatio, rotations, power);
}
