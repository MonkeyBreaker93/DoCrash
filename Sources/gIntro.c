/*
 * gIntro.c
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#include "gIntro.h"
#include "gDef.h"
#include "def.h"
#include "mDelays.h"
#include "mLcd.h"
#include "gEvent.h"

void gIntro_Show(GameStatesEnum *GameState)
{
	static IntroStatesEnum aIntro=kInit;
	static int aIndexT1;
	static int counter=0;
	static bool amen=false;
	struct gEventSWsStruct aSw;
	switch (aIntro)
	{
		case kInit:
			aIndexT1=mDelay_GetDelay(400);
			aIntro=kRunning;
			gEvent_ResetSw();
			break;
		case kRunning:
			gEvent_GetSw(&aSw);
			if(aSw.Sw1.utd||aSw.Sw2.dtu||aSw.Sw3.dtu||aSw.Sw4.dtu)
			{
				aIntro=kQuit;
			}
			if(mDelay_IsDelayDone(aIndexT1))
			{
				mLcd_Clear();
				mLcd_Write(0, 1,0+(counter/2));
				if(counter==14)
					mLcd_Write(2, 1,1+(counter/2));
				else
					mLcd_Write(1, 1,1+(counter/2));
				mLcd_WriteAt("DoCrash v0.0",0,2);
				amen=!amen;
				if(amen)
				{
					mLcd_Write(6, 0,0);
					mLcd_Write(6, 0,15);
					if(counter<14)
						mLcd_Write(5, 1,15-(counter/2));
				}
				else
				{
					mLcd_Write(5, 0,0);
					mLcd_Write(5, 0,15);
					if(counter<14)
						mLcd_Write(6, 1,15-(counter/2));
				}
				counter++;
				if(counter>16)
				{
					aIntro=kQuit;
				}
				mDelay_DelayRelease(aIndexT1);
				aIndexT1=mDelay_GetDelay(400);
			}
			break;
		case kQuit:
			mDelay_DelayRelease(aIndexT1);
			*GameState=kMenu;
			break;
	}
}
