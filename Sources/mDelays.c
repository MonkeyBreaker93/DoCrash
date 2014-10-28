/*
 * mDelays.c
 *
 *  Created on: Oct 14, 2014
 *      Author: sebastie.glauser
 */

#include "iPit.h"
#include "mDelays.h"

void mDelay_Setup()
{
	iPit_Config(0x1f40,0x13880);
	iPit_StrartPit(kPit0);
	iPit_InitDelay();
}
int mDelay_GetDelay(unsigned int aCount)
{
	return iPit_GetDelay(aCount);
}
void mDelay_DelayRelease(int aIndex)
{
	iPit_DelayRelease(aIndex);
}
bool mDelay_IsDelayDone(int aIndex)
{
	return iPit_IsDelayDone(aIndex);
}
bool mDelay_ms(unsigned int ams)
{
	int aIndex=mDelay_GetDelay(ams);
	if(aIndex<0)
		return false;
	while(mDelay_IsDelayDone(aIndex));
	mDelay_DelayRelease(aIndex);
	return true;
}
