/*
 * mDelays.h
 *
 *  Created on: Oct 14, 2014
 *      Author: sebastie.glauser
 */



#ifndef MDELAYS_H_
#define MDELAYS_H_

void mDelay_Setup();
int mDelay_GetDelay(unsigned int aCount);
void mDelay_DelayRelease(int aIndex);
bool mDelay_IsDelayDone(int aIndex);
bool mDelay_ms(unsigned int ams);
#endif /* MDELAYS_H_ */
