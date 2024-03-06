#pragma config(Sensor, S1,     Light,          sensorEV3_Color)
#pragma config(Sensor, S2,     touchRight,     sensorEV3_Touch)
#pragma config(Sensor, S3,     Gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S4,     ultraSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          GyroMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          Left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          Right,         tmotorEV3_Large, PIDControl, driveRight, encoder)
//reassigning sensors and motors using built-in pragma setup


task main()
{
	int Pow; //assigning variables

	eraseDisplay(); //Erases display and leaves a blank screen

	resetGyro(S3); //resets the gryo to 0
	setMotorSpeed(GyroMotor, 5);

	while (true)
	{
		Pow = 50; //sets the power to 50% while the gyro is at 0

		displayCenteredTextLine(2,"Angle =%d",(getGyroDegrees(S3))); //displays current degree

		setMotorSpeed(Left, Pow+(getGyroDegrees(S3))); //arthimetics for determining the power
		setMotorSpeed(Right, Pow+(getGyroDegrees(S3)));


		if ((getGyroDegrees(S3)) >= 50) //if the degree goes above 50 it reverse the gyro motor
		{
			setMotorSpeed(GyroMotor, -5);
		} //end if

		if ((getGyroDegrees(S3)) <= -50)//if the degree goes below -50 it reverse the gyro motor
		{
			setMotorSpeed(GyroMotor,5);
		}	//end if

	} //end while


}//end program
