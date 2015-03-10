#ifndef AUTOPICKUP_H_
#define AUTOPICKUP_H_

/* TODO:
 *
 *  (Requires testing) Move the forks to the correct height
 *  (By !Zack and etc) Align with crates (this may require to move a bit forward or back and fire the solenoid then move up a bit
 *  (Requires testing) Put a crate down on a stack then pick them up
 *  (Requires testing) Put crate down, (TODO) rotate around the stack (later will push forward into auto zone)
 */

#include "WPILib.h"

class AutoPickupGroup: public CommandGroup
{
public:
	AutoPickupGroup();
};

#endif /* AUTOPICKUP_H_ */
