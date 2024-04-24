void turnGyro(long power, long turnDegree);//the speed of the motors during the turn, how many degrees motorC it will turn

void drive(long nMotorRatio, long dist, long power);// the ratio of the motors, how far in centimatres to travel, how fast to travel


#define Centimetre 20.93 //symbolic names

task main()
{
	//assigning variables
	int notblack=0;
	int locX=1;
	int locY=1;
	int destX=1;
	int destY=1;
	int direction = 2;
	
	//asking the user for the location input and the destination input coordinates
	while (getButtonPress(buttonEnter) == 0)
	{
		sleep(80);
		if (getButtonPress(buttonRight))
		{
			locX++;
		}
		
		if (getButtonPress(buttonLeft))
		{
			locX--;
		}
		
		if (getButtonPress(buttonUp))
		{
			locY++;
		}
		
		if (getButtonPress(buttonDown))
		{
			locY--;
		}
		
		displayCenteredBigTextLine(3, "Location: [%d,%d]",locX,locY);
	}		
	sleep(100);
	//asking the user for the location input and the destination input coordinates
	while (getButtonPress(buttonEnter) == 0)
	{
		sleep(80);
		if (getButtonPress(buttonRight))
		{
			destX++;
		}
		
		if (getButtonPress(buttonLeft))
		{
			destX--;
		}
		
		if (getButtonPress(buttonUp))
		{
			destY++;
		}
		
		if (getButtonPress(buttonDown))
		{
			destY--;
		}
		
		displayCenteredBigTextLine(3, "Destination: [%d,%d]",destX,destY);
	}	
	//assigning sensor types
	SensorType[0]=sensorEV3_Touch;
	SensorType[1]=sensorEV3_Touch;
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
		//senses for whether it has passed a black line, if so take away or add value 
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
		//box avoidance code for when the robot hits a wall, goes around it either up or down and contiunes on its path
		if ((SensorValue[0] == 1 && direction==2) || (SensorValue[1] == 1 && direction==2))
		{
			turnGyro(40,258);
			drive(0, 30, 100);
			turnGyro(40,90);
			locY++;
			locY++;
			setMotorSpeed(1, 100);
			setMotorSpeed(2, 100);
		}
	}
	//if the location starts at 1, it will add another one to account the outside the box detection
	if (locX == 1)
	{
		locX++;
	}
	
	while (locX > destX)
		
	{
		while (direction < 4)
		{
			turnGyro(40,88);
			direction++;
		}
		
		setMotorSpeed(1, 100);
		setMotorSpeed(2, 100);		
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
		if ((SensorValue[0] == 1 && locX>=locY) || (SensorValue[1] == 1 && locX>=locY))
		{
			//box avoidance code for when the robot hits a wall, goes around it either up or down and contiunes on its path
			turnGyro(40,79);
			drive(0, 30, 100);
			turnGyro(40,270);
			locY++;
			locY++;
			setMotorSpeed(1, 100);
			setMotorSpeed(2, 100);
		}
		if ((SensorValue[0] == 1 && locX<=locY) || (SensorValue[1] == 1 && locX<=locY))
		{
			//box avoidance code for when the robot hits a wall, goes around it either up or down and contiunes on its path
			turnGyro(40,262);
			drive(0, 30, 100);
			turnGyro(40,90);
			locY--;
			locY--;
			locX++;
			setMotorSpeed(1, 100);
			setMotorSpeed(2, 100); 
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
	
	//change the direction of the robot depending on the direction its facing
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
		if ((SensorValue[0] == 1) || (SensorValue[1] == 1))
		{
			//box avoidance code for when the robot hits a wall, goes around it either up or down and contiunes on its path
			turnGyro(40,262);
			drive(0, 30, 100);
			turnGyro(40,90);
			locY++;
			locY++;
			setMotorSpeed(1, 100);
			setMotorSpeed(2, 100);
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
			if ((SensorValue[0] == 1 && direction==2) || (SensorValue[1] == 1 && direction==1))
			{
				//box avoidance code for when the robot hits a wall, goes around it either up or down and contiunes on its path
				turnGyro(40,262);
				drive(0, 30, 100);
				turnGyro(40,90);
				locY++;
				locY++;
				setMotorSpeed(1, 100);
				setMotorSpeed(2, 100);
			}
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
	
	resetMotorEncoder(1); //reset both motor encoders 
	resetMotorEncoder(2);
	
	setMotorSyncEncoder(1, 2, nMotorRatio, rotations, power);
}
