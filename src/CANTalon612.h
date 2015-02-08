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
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, Preferences* pfs, bool inverted=false, bool override=false);
	CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted=false, bool override=false);
	CANTalon612(uint32_t port, Encoder* e, Preferences* pfs, bool override=false);
	CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override=false);
	virtual ~CANTalon612();
private:
	void initPID(Preferences* pfs, bool override);
	void initPID(float p, float i, float d, bool override);
	void readPrefs();
	bool checkPrefs();
	int writePrefs(float p, float i, float d);
	float P;
	float I;
	float D;
	void PIDWrite(float output);
	float* vals[3];
	Preferences* prefs;
	PIDController* pid;
	Encoder* encoder;
};

#endif /* SRC_CANTALON612_H_ */
