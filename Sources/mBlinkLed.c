/*
 * mBlinkLed.c
 *
 *  Created on: Oct 14, 2014
 *      Author: sebastie.glauser
 */

#include "mLeds.h"
#include "mSwitch.h"
#include "def.h"
#include "mDelays.h"
#include "mBlinkLed.h"

void mBlinkLed_init()
{
	mLed_Setup();
	mDelay_Setup();
	EnableInterrupts();
}

void mBlinkLed_Setup(struct BlinkLedStruct *aStructPtr,unsigned int aDelay,unsigned int aOutput)
{
	aStructPtr->Delay=aDelay;
	aStructPtr->OldValue=false;
	aStructPtr->Output=aOutput;
	aStructPtr->State=kCreateDelay;
}

void mBlinkLed(struct BlinkLedStruct *aStructPtr)
{
	switch(aStructPtr->State)
	{
		case kCreateDelay:
			aStructPtr->Index=mDelay_GetDelay(aStructPtr->Delay);
			if(aStructPtr->Index==-1)
				aStructPtr->State=kError;
			else
				aStructPtr->State=kWaitDelay;
			break;
		case kWaitDelay:
			if(mDelay_IsDelayDone(aStructPtr->Index))
				aStructPtr->State=kChangeState;
			break;
		case kChangeState:
			mDelay_DelayRelease(aStructPtr->Index);
			aStructPtr->OldValue=!aStructPtr->OldValue;
			mLed_Write(aStructPtr->Output, aStructPtr->OldValue);
			aStructPtr->State=kCreateDelay;
			break;
		default:
			aStructPtr->State=kError;
			/*
			 *  Add error code here
			 */
			break;
	}
}

void mBlinkLed_Stop(struct BlinkLedStruct *aStructPtr)
{
	mDelay_DelayRelease(aStructPtr->Index);
	mLed_Write(aStructPtr->Output, kOff);
	aStructPtr->State=kCreateDelay;
}
