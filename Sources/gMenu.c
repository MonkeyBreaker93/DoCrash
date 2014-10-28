/*
 * gIntro.c
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#include "gMenu.h"
#include "gDef.h"
#include "def.h"
#include "mDelays.h"
#include "mLcd.h"
#include "gEvent.h"

void gMenu_Show(GameStatesEnum *GameState)
{
	static MenuStatesEnum aMenu=kMenuInit;
	static MenuSelectionStatesEnum aSelectMenu=kStartGame;
	static int aIndexT1;
	static bool amen=false;
	struct gEventSWsStruct aSw;
	switch (aMenu)
	{
		case kMenuInit:
			aIndexT1=mDelay_GetDelay(400);
			aMenu=kMenuRunning;
			aSelectMenu=kStartGame;
			gEvent_ResetSw();
			break;
		case kMenuRunning:
			gEvent_GetSw(&aSw);
			if(aSw.Sw1.dtu)
			{
				switch(aSelectMenu)
				{
					case kStartGame:
						aSelectMenu=kCredit;
						break;
					case kUpgrade:
						aSelectMenu=kStartGame;
						break;
					case kCredit:
						aSelectMenu=kUpgrade;
						break;
				}
				gEvent_ResetSw();
			}
			if(aSw.Sw4.dtu)
			{
				switch(aSelectMenu)
				{
					case kStartGame:
						aSelectMenu=kUpgrade;
						break;
					case kUpgrade:
						aSelectMenu=kCredit;
						break;
					case kCredit:
						aSelectMenu=kStartGame;
						break;
				}
				gEvent_ResetSw();
			}
			if(aSw.Sw2.dtu||aSw.Sw3.dtu)
			{
				switch(aSelectMenu)
				{
					case kStartGame:
						aMenu=kMenuQuit;
						*GameState=kGame;
						break;
					case kUpgrade:
						break;
					case kCredit:
						break;
				}
				gEvent_ResetSw();
			}
			if(mDelay_IsDelayDone(aIndexT1))
			{
				amen=!amen;
				gMenu_Print(amen,aSelectMenu);
				mDelay_DelayRelease(aIndexT1);
				aIndexT1=mDelay_GetDelay(400);
			}
			break;
		case kMenuQuit:
			aMenu=kMenuInit;
			mDelay_DelayRelease(aIndexT1);
			break;
	}
}

void gMenu_PrintMens(bool amen)
{
	if(amen)
	{
		mLcd_Write(6, 0,0);
		mLcd_Write(6, 0,15);
	}
	else
	{
		mLcd_Write(5, 0,0);
		mLcd_Write(5, 0,15);
	}
}

void gMenu_Print(bool amen,MenuSelectionStatesEnum aSelectMenu)
{
	mLcd_Clear();
	gMenu_PrintMens(amen);
	mLcd_WriteAt("DoCrash Menu",0,2);
	switch(aSelectMenu)
	{
		case kStartGame:
			mLcd_WriteAt("<  Start Game  >",1,0);
			break;
		case kUpgrade:
			mLcd_WriteAt("<   Upgrades   >",1,0);
			break;
		case kCredit:
			mLcd_WriteAt("<    Credits   >",1,0);
			break;
	}
}
