/*
 * mBlinkLed.h
 *
 *  Created on: Oct 14, 2014
 *      Author: sebastie.glauser
 */

#ifndef MBLINKLED_H_
#define MBLINKLED_H_

#include "def.h"

typedef enum
{
	kCreateDelay,
	kWaitDelay,
	kChangeState,
	kError,
}StatesEnum;

struct BlinkLedStruct
{
	unsigned int Delay ;
	bool OldValue;
	StatesEnum State;
	unsigned int Output ;
	int Index ;
};

void mBlinkLed_init();
void mBlinkLed_Setup(struct BlinkLedStruct *aStructPtr,unsigned int aDelay,unsigned int aOutput);
void mBlinkLed(struct BlinkLedStruct *aStructPtr);

#endif /* MBLINKLED_H_ */
