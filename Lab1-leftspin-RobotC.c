
task main()
{
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 50);

	sleep(2200);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 50);

	sleep(2700);


}
