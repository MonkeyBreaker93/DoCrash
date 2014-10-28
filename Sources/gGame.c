/*
 * gGame.c
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */


#include "gGame.h"
#include "gDef.h"
#include "def.h"
#include "mDelays.h"
#include "mLcd.h"
#include "gEvent.h"
#include "gObjects.h"
#include "mLeds.h"
#include <stdio.h>

int aScore=0;
int aOldScore=0;

void gGame_Show(GameStatesEnum *GameState)
{
	static GamesStatesEnum aMenu=kGameInit;
	static int aIndexT1;
	static bool amen=false;
	static bool aVpos=false;
	struct gEventSWsStruct aSw;
	static char fuel=0xFF;
	static int counter=0;
	char scoretxt[33];
	switch (aMenu)
	{
		case kGameInit:
			aIndexT1=mDelay_GetDelay(100);
			aMenu=kGameRunning;
			aScore=0;
			gObjects_Init();
			gEvent_ResetSw();
			fuel=0xFF;
			break;
		case kGameRunning:
			gEvent_GetSw(&aSw);
			if(aSw.Sw2.dtu)
			{
				aVpos=!aVpos;
				gGame_Print(amen,aVpos);
				gEvent_ResetSw();
			}
			if(mDelay_IsDelayDone(aIndexT1))
			{
				amen=!amen;
				if(amen)
				{
					if(counter>10)
					{
						counter=0;
						fuel=fuel>>1;
					}
					counter++;
					gObjects_CreateMens();
					gObjects_CreateTals();
					gObjects_CreateFuels();
					aScore+=gObjects_MoveMen(aVpos);
					if(gObjects_MoveTal(aVpos))
						aMenu=kCrash;
					if(gObjects_MoveFuel(aVpos))
					{
						fuel=0xFF;
						counter=0;
					}
					if(fuel==0)
						aMenu=kOutOfFuel;
					mLed_Write(kAll,kOff);
					mLed_Write(fuel,kOn);
				}
				
				gGame_Print(amen,aVpos);
				mDelay_DelayRelease(aIndexT1);
				if(aScore<10)
				{
					aIndexT1=mDelay_GetDelay(300-aScore*10);
				}
				else if(aScore<20)
				{
					aIndexT1=mDelay_GetDelay(200-(aScore-10)*5);
				}
				else if(aScore<40)
				{
					aIndexT1=mDelay_GetDelay(150-(aScore-20)*3);
				}
				else if(aScore<60)
				{
					aIndexT1=mDelay_GetDelay(90-(aScore-40)*2);
				}
				else
				{
					aIndexT1=mDelay_GetDelay(50);
				}
			}
			break;
		case kCrash:
			mLcd_CreateMonkey();
			mLcd_Clear();
			mLcd_Write(2,0,0);
			mLcd_Write(1,0,1);
			mLcd_Write(0,0,2);
			mLcd_Write(5,1,0);
			mLcd_Write(4,1,1);
			mLcd_Write(3,1,2);
			sprintf(scoretxt,"%d",aScore);
			mLcd_WriteAt(scoretxt, 1,5);
			mLcd_WriteAt("Score", 0,5);
			aMenu=kGameQuit;
			break;
		case kOutOfFuel:
			mLcd_CreateMonkey();
			mLcd_Clear();
			mLcd_Write(2,0,0);
			mLcd_Write(1,0,1);
			mLcd_Write(0,0,2);
			mLcd_Write(5,1,0);
			mLcd_Write(4,1,1);
			mLcd_Write(3,1,2);
			sprintf(scoretxt,"%d",aScore);
			mLcd_WriteAt(scoretxt, 1,5);
			mLcd_WriteAt("Score", 0,5);
			aMenu=kGameQuit;
			break;
		case kGameQuit:
			gEvent_GetSw(&aSw);
			if(aSw.Sw2.dtu)
			{
				*GameState=kMenu;
				aMenu=kGameInit;
				mDelay_DelayRelease(aIndexT1);
				gEvent_ResetSw();
				mLcd_CreateAllChar();
			}
			break;
	}
}


void gGame_Print(bool amen,bool aVpos)
{
	char scoretxt[4];
	mLcd_Clear();
	sprintf(scoretxt,"%d",aScore);
	if(aScore<10)
		mLcd_WriteAt(scoretxt, 0,15);
	else if(aScore<100)
		mLcd_WriteAt(scoretxt, 0,14);
	else if(aScore<1000)
		mLcd_WriteAt(scoretxt, 0,13);
	else 
		mLcd_WriteAt(scoretxt, 0,12);
	gObjects_PrintMen(amen);
	gObjects_PrintFuel();
	gObjects_PrintTal();
	mLcd_Write(0, aVpos,0);
	if(aOldScore==aScore)
		mLcd_Write(1, aVpos,1);
	else
		mLcd_Write(2, aVpos,1);
	aOldScore=aScore;
}
