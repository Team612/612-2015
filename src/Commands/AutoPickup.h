#ifndef AUTOPICKUP_H_
#define AUTOPICKUP_H_

/* TODO:
 *
 *  Move the forks to the correct height
 *  Crates (this may require to move a bit forward or back and fire the solenoid then move up a bit
 *  Put a crate down on a stack then pick them up
 *  Put crate down, rotate around the stack (later will push forward into auto zone)
 */

class AutoPickupGroup: public CommandGroup
{
public:
	AutoPickupGroup();
};

#endif /* AUTOPICKUP_H_ */
