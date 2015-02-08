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

class CANTalon612: public CANTalon
{
public:
	/*
	 * For the constructor, we need a channel to make the actual talon (This would be the CAN ID
	 * Then we need an encoder, either by getting the channels and constructing them ourselves, or the actual encoder
	 * After that, we need to get PID values. This can be done by either importing preferences or specifying
	 * The override will save the new values over the old ones
	 *
	 * If PID values are not specified, then they will be recalled from Preferences. If they dont exist there, they will default to 0.0
	 */
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, bool inverted=false);
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted=false, bool override=false);
	CANTalon612(uint32_t port, Encoder* e);
	CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override=false);
	virtual ~CANTalon612();
	///Will set it to a value using PID
	void Set(float value);
	///returns the output of the motor
	float getOutput();
private:
	///Uses this one for if it is just grabbing from preferences
	void initPID();
	///uses this one for if it needs to set PID or needs to overwrite written values
	void initPID(float p, float i, float d, bool override);
	///Reads preferences and stores them into P I and D
	void readPrefs();
	///Checks to see if there are stored values for PID
	bool checkPrefs();
	///Writes the values to the preferences to be loaded later
	int writePrefs(float p, float i, float d);
	///Sets the maximum output
	void setMaxOutput(float out);
	//These two below will get from file NOT from the class variable
	float getMaxOutput();
	/// PID Values and maximum output
	float P;
	float I;
	float D;
	float maxOut;
	///Depreciated?
	void PIDWrite(float output);
	Preferences* prefs;
	PIDController* pid;
	Encoder* encoder;
};

#endif /* SRC_CANTALON612_H_ */
