#include "autito.h"


void setDirectionAngle(int angulo, Servo &motor){
	if(angulo < 0){
		angulo *= -1;
	}

	angulo = constrain(angulo, 10, 170);
	motor.write(angulo);
}

/*
a partir de 35 empieza a funcionar.
*/
void setMotorSpeed(int speed, AF_DCMotor &motor)
{
	speed = constrain(speed, -100, 100);

	if(speed < 0)
	{
		speed *= -1;
		motor.run(BACKWARD);
	}
	else if(speed > 0)
	{
		motor.run(FORWARD);
	}
	else
	{
		motor.run(RELEASE);
	}

	speed = map(speed, 0, 100, 0, 255);
	motor.setSpeed(speed);
}

void getBluetoohData(int &angulo, bool &acelerar, bool &frenar){

	while(!Serial.available());

    String ang = "90";
	String ace = "0";
	String fre = "1";

	while(Serial.available())
    {
    	ang = Serial.readStringUntil('|');
    	ace = Serial.readStringUntil('|');
    	fre = Serial.readStringUntil('\n');
    }

    angulo = ang.toInt();
	acelerar = (ace.toInt() == 1);
	frenar = (fre.toInt() == 1);

    // limpio el buffer
    // Serial.flush();
}