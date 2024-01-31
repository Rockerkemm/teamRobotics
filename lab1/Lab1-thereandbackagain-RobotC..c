
task main()
{
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 50);

	sleep(5000);

	setMotorSpeed(motorB, 25);
	setMotorSpeed(motorC, -25);

	sleep(1400);

	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 50);

	sleep(5000);

	setMotorSpeed(motorB, 25);
	setMotorSpeed(motorC, -25);

	sleep(1400);
}
