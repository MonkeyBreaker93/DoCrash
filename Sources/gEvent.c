/*
 * gEvent.c
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#include "def.h"
#include "mDelays.h"
#include "mSwitch.h"
#include "gEvent.h"

unsigned int sIndex2;
PushButEventStruct aSw1,aSw2,aSw3,aSw4;

void gEvent_setup()
{
	mSwitch_Setup();
	mSwitch_EventSetup(&aSw1,kPushButSW1);
	mSwitch_EventSetup(&aSw2,kPushButSW2);
	mSwitch_EventSetup(&aSw3,kPushButSW3);
	mSwitch_EventSetup(&aSw4,kPushButSW4);
	sIndex2=mDelay_GetDelay(20);
}

void gEvent_Sw()
{
	if(mDelay_IsDelayDone(sIndex2))
	{
		mSwitch_EventMng(&aSw1);
		mSwitch_EventMng(&aSw2);
		mSwitch_EventMng(&aSw3);
		mSwitch_EventMng(&aSw4);
		mDelay_DelayRelease(sIndex2);
		sIndex2=mDelay_GetDelay(20);
	}
}

void gEvent_GetSw(struct gEventSWsStruct *gSW)
{
	gSW->Sw1.dtu=aSw1.dtu;
	gSW->Sw2.dtu=aSw2.dtu;
	gSW->Sw3.dtu=aSw3.dtu;
	gSW->Sw4.dtu=aSw4.dtu;
	gSW->Sw1.utd=aSw1.utd;
	gSW->Sw2.utd=aSw2.utd;
	gSW->Sw3.utd=aSw3.utd;
	gSW->Sw4.utd=aSw4.utd;
}

void gEvent_ResetSw()
{
	aSw1.dtu=false;
	aSw2.dtu=false;
	aSw3.dtu=false;
	aSw4.dtu=false;
	aSw1.utd=false;
	aSw2.utd=false;
	aSw3.utd=false;
	aSw4.utd=false;
}
