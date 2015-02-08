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
	 */
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, Preferences* pfs, bool inverted=false, bool override=false);
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted=false, bool override=false);
	CANTalon612(uint32_t port, Encoder* e, Preferences* pfs, bool override=false);
	CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override=false);
	virtual ~CANTalon612();
	void Set(float value);
	float getOutput();
private:
	//
	void initPID(Preferences* pfs, bool override);
	void initPID(float p, float i, float d, bool override);
	void readPrefs();
	bool checkPrefs();
	int writePrefs(float p, float i, float d);
	void setMinOutput(float out);
	void setMaxOutput(float out);
	//These two below will get from file NOT from the class variable
	float getMinOutput();
	float getMaxOutput();
	float P;
	float I;
	float D;
	float maxOut;
	float minOut;
	void PIDWrite(float output);
	Preferences* prefs;
	PIDController* pid;
	Encoder* encoder;
};

#endif /* SRC_CANTALON612_H_ */
