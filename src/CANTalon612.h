/*
 * CANTalon612.h
 *
 *  Created on: Feb 8, 2015
 *      Author: zachary
 */

#ifndef SRC_CANTALON612_H_
#define SRC_CANTALON612_H_

#include <Encoder.h>
#include <PIDController.h>
#include <Preferences.h>
#include <CANTalon.h>

class CANTalon612: public SpeedController {
public:
	/*
	 * For the constructor, we need a channel to make the actual talon
	 * (This would be the CAN ID Then we need an encoder, either by getting
	 * the channels and constructing them ourselves, or the actual encoder
	 * After that, we need to get PID values. This can be done by either
	 * importing preferences or specifying The override will save the new
	 * values over the old ones
	 *
	 * If PID values are not specified, then they will be recalled from
	 * Preferences. If they dont exist there, they will default to 0.0
	 */
	CANTalon612(char* name, uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted=false);
	CANTalon612(char* name, uint32_t port, Encoder* e, float p, float i, float d);
	CANTalon612(char* name, CANTalon* t, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted=false);
	CANTalon612(char* name, CANTalon* t, Encoder* e, float p, float i, float d);
	virtual ~CANTalon612();
	///Will set it to a value using PID
	void Set(float value, uint8_t syncGroup=0);
	///returns the output of the motor
	float Get();
	void Disable();
	float getEncoderValue();
	char* motor_name;
private:
	///uses this one for if it needs to set PID or needs to overwrite written values
	void initPID(float p, float i, float d);
	///Reads preferences and stores them into P I and D
	void readPrefs();
	///Checks to see if there are stored values for PID
	bool checkPrefs();
	///Writes the values to the preferences to be loaded later
	int writePrefs(float encoderRate);
	/// PID Values and maximum output
	float P;
	float I;
	float D;
	float encoder_rate;
	///Depreciated?
	void PIDWrite(float output);
	Preferences* prefs;
	PIDController* pid;
	Encoder* encoder;
	CANTalon* talon;
	const float DEFAULT_ENCODER_RATE = 1.0f;//TODO make this a real rate
};

#endif /* SRC_CANTALON612_H_ */
