/*
 * mLeds.h
 *
 *  Created on: Oct 3, 2014
 *      Author: julian.burellap
 */

#ifndef MLEDS_H_
#define MLEDS_H_

#include "def.h"
#include "iDio.h"

typedef enum
{
	kLed1=0x01,
	kLed2=0x02,
	kLed3=0x04,
	kLed4=0x08,
	kLed5=0x10,
	kLed6=0x20,
	kLed7=0x40,
	kLed8=0x80,
	kAll=0xFF
}LedMaskEnum;


void mLed_Write(LedMaskEnum aMask, LedStateEnum aState);
void mLed_Setup(void);

#endif /* MLEDS_H_ */
