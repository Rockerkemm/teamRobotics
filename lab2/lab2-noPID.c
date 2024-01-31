
void turn90degreesLeft()
{
	setMotorSpeed(left, -50);
	setMotorSpeed(right, 50);
	sleep(1000);
}

void turn90degreesRight()
{
	setMotorSpeed(left, 50);
	setMotorSpeed(right, -50);
	sleep(1000);
}

void goForward1second()
{
	setMotorSpeed(left, 50);
	setMotorSpeed(right, 50);
	sleep(1000);
}

void swingRight90degrees()
{
	setMotorSpeed(left, 50);
	setMotorSpeed(right, 0);
	sleep(1000);
}

void swingLeft90degrees()
{
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 50);
	sleep(1000);
}

void reverse1second()
{
	setMotorSpeed(left, -50);
	setMotorSpeed(right, -50);
	sleep(1000);
}


task main()
{
	turn90degreesLeft();
	turn90degreesRight();
	goForward1second();
	swingRight90degrees();
	swingLeft90degrees();
	reverse1second();
}
