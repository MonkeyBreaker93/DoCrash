/*
 * mLeds.c
 *
 *  Created on: Oct 3, 2014
 *      Author: julian.burellap
 */

#include "mLeds.h"
#include "iDio.h"

void mLed_Write(LedMaskEnum aMask, LedStateEnum aState)
{
	if(aMask&kLed1)
		iDio_SetPort(kPortD, kBit2, aState);
	
	if(aMask&kLed2)
		iDio_SetPort(kPortA, kBit13, aState);
	
	if(aMask&kLed3)
		iDio_SetPort(kPortC, kBit9, aState);
	
	if(aMask&kLed4)
		iDio_SetPort(kPortC, kBit8, aState);
	
	if(aMask&kLed5)
		iDio_SetPort(kPortA, kBit5, aState);
	
	if(aMask&kLed6)
		iDio_SetPort(kPortA, kBit4, aState);
	
	if(aMask&kLed7)
		iDio_SetPort(kPortA, kBit12, aState);
	
	if(aMask&kLed8)
		iDio_SetPort(kPortD, kBit3, aState);
}

void mLed_Setup(void)
{
	iDio_EnablePortClk();

	iDio_PinConfig(kPortA, kBit4|kBit5|kBit12|kBit13,kGpio);
	iDio_PinConfig(kPortC, kBit9|kBit8,kGpio);
	iDio_PinConfig(kPortD, kBit2|kBit3,kGpio);
	
	iDio_SetPortDirection(kPortA, kBit4|kBit5|kBit12|kBit13,kOutput);
	iDio_SetPortDirection(kPortC, kBit9|kBit8,kOutput);
	iDio_SetPortDirection(kPortD, kBit2|kBit3,kOutput);
}
