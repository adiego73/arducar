#ifndef __AUTITO__H
#define __AUTITO__H

#include "Arduino.h"
#include <Servo.h>
#include <SoftwareSerial.h>
#include "AFMotor.h"


#define DERECHA 45
#define IZQUIERDA 135 

#define BT_RX 8 // A0
#define BT_TX 7 // A1

// Servo direccion;
//SoftwareSerial bluetooth(10,11); //Rx y Tx


void setMotorSpeed(int speed, AF_DCMotor &motor);
void setDirectionAngle(int angulo, Servo &motor);
void getBluetoohData(int &angulo, bool &acelerar, bool &frenar);

// fin de __AUTITO__H
#endif