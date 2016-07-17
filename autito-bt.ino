#include "autito.h"

// MOTORES
AF_DCMotor motor(1, MOTOR12_64KHZ);
Servo direccion;

// BLUETOOTH
// http://electronics.stackexchange.com/questions/84271/arduino-uno-bluetooth-over-analog
// http://forum.arduino.cc/index.php?topic=406321.0
// SoftwareSerial bluetooth(BT_TX,BT_RX); //Rx y Tx


//	VARIABLES GLOBALES
int anguloDireccion = 0;
bool acelerar = false;
bool frenar = false;

void setup()
{
	Serial.begin(9600);

	while (Serial.available() > 0) {
    	Serial.read();
	}

	Serial.flush();

	// pinMode(BT_TX, INPUT);
	// pinMode(BT_RX, OUTPUT);
	
	// bluetooth.begin(9600);

	direccion.attach(9);

	delay(100);
	direccion.write(90);
}

void loop()
{

	getBluetoohData(anguloDireccion, acelerar, frenar);

	setDirectionAngle(anguloDireccion, direccion);

	if(acelerar)
	{
		setMotorSpeed(100, motor);
	}

	if(frenar)
	{
		setMotorSpeed(0, motor);
	}
}