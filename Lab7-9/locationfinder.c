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

	turn90(10, 90);

}//end program

void turn90(long power, long turnDegree)
{
	resetGyro(sensorEV3_Gyro);
	while(getGyroDegrees(sensorEV3_Gyro)-1<turnDegree-3)//the minus is to account for the lag
	{
		displayCenteredBigTextLine(6,"Gyro:%d",getGyroDegrees(sensorEV3_Gyro));//debbugging text
		setMotorSpeed(motorB,power);//motors are turning
		setMotorSpeed(motorC,-power);
	}
	setMotorSpeed(motorB,0);//stopping the motors after
	setMotorSpeed(motorC,0);

}
