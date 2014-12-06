#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorSl,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorSp,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c" // adds file to take the controllers

/* Some configuration/wiring settings for this code:
 look at the config file
*/






task main(){//the start of the robot acutally doing things

		//some starting variables
		int jBuffer = 25; //buffer for joysticks
		int sTime = 10; //sleep time, reaction time
		int dSpeed = 25; //drive speed
		int tSpeed = 10; //turning speed
		int lSpeed = 25; //lift speed
		int slSpeed = 10; //slide speed
		int spSpeed = 25; //spinner speed
		int gSpeed = 5; //servo speed


		//waitForStart(); //waits for driving period to start, only in comp <================== change for comp =====================

	while(true){// the driving loop

		getJoystickSettings(joystick);//updates joystick

		if(abs(joystick.joy1_x1) < jBuffer && abs(joystick.joy1_y1) < jBuffer){ //stop
			motor[motorA] = 0;
			motor[motorB] = 0;
			Sleep(sTime);

	}

		if(abs(joystick.joy1_x1) < jBuffer && (joystick.joy1_y1) > jBuffer){ //forwards
			motor[motorA] = dSpeed;
			motor[motorB] = dSpeed;
			Sleep(sTime);

	}

		if(abs(joystick.joy1_x1) < jBuffer && (joystick.joy1_y1) < -jBuffer){ //backwards
			motor[motorA] = -dSpeed;
			motor[motorB] = -dSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) > jBuffer && abs(joystick.joy1_y1) < jBuffer){ //right point
			motor[motorA] = tSpeed;
			motor[motorB] = -tSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) < -jBuffer && abs(joystick.joy1_y1) < jBuffer){ //left point
			motor[motorA] = -tSpeed;
			motor[motorB] = tSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) > jBuffer && (joystick.joy1_y1) > jBuffer){ //forwards right swing
			motor[motorA] = 0;
			motor[motorB] = tSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) > jBuffer && (joystick.joy1_y1) < -jBuffer){ //backwards right swing
			motor[motorA] = 0;
			motor[motorB] = -tSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) < -jBuffer && (joystick.joy1_y1) > jBuffer){ //forwards left swing
			motor[motorA] = 0;
			motor[motorB] = tSpeed;
			Sleep(sTime);

	}

		if((joystick.joy1_x1) < -jBuffer && (joystick.joy1_y1) < -jBuffer){ //backwards left swing
			motor[motorA] = 0;
			motor[motorB] = -tSpeed;
			Sleep(sTime);

	}

	/*if(abs(joystick.joy1_y1) < jBuffer){ //stop right
		motor[motorA] = 0;
		Sleep(sTime);
	}

	if(abs(joystick.joy1_y2) < jBuffer){ //stop left
		motor[motorB] = 0;
		Sleep(sTime);
	}

	if((joystick.joy1_y1) > jBuffer){ //forwards right
		motor[motorA] = dSpeed;
		Sleep(sTime);
	}

	if((joystick.joy1_y2) > jBuffer){ //forwards left
		motor[motorB] = dSpeed;
		Sleep(sTime);
	}

	if((joystick.joy1_y1) < -jBuffer){//backwards right
		motor[motorA] = -dSpeed;\
		Sleep(sTime);
	}

	if((joystick.joy1_y2) < -jBuffer){//backwards left
		motor[motorB] = -dSpeed;
		Sleep(sTime);
	}*/

	//arm lift
	if(abs(joystick.joy2_y1) < jBuffer){//lift stop
		motor[motorL] = 0;
		Sleep(sTime);
	}

	if((joystick.joy2_y1) > jBuffer){//lift up?
		motor[motorL] = lSpeed;
		sleep(sTime);
	}

	if((joystick.joy2_y1) < -jBuffer){//lift down?
		motor[motorL] = -lSpeed;
		Sleep(sTime);
	}

	//slide speed
	if(abs(joystick.joy2_y2) < jBuffer){//slide stop
		motor[motorSl] = 0;
		Sleep(sTime);
	}

	if((joystick.joy2_y2) > jBuffer){//slide forwards?
		motor[motorSl] = slSpeed;
		Sleep(sTime);
	}

	if((joystick.joy2_y2) < -jBuffer){//slide backwards?
		motor[motorSl] = -slSpeed;
		Sleep(sTime);
	}

	//spinner
	if( joystick.joy2_TopHat == -1){//spin stop
		motor[motorSp] = 0;
		Sleep(sTime);
		}

	if( joystick.joy2_TopHat == 0 ){ //spin forwards?
		motor[motorSp] = spSpeed;
		Sleep(sTime);

	}

	if( joystick.joy2_TopHat == 4) { //spin backwards?
		motor[motorSp] = -spSpeed;
		Sleep(sTime);
	}


	//servo
	servo[servo1] = abs(joystick.joy1_y2);


}//end of while true loop
}//end of task main
