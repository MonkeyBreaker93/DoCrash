/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "main.h"
#include "mCpu.h"
#include "mBlinkLed.h"
#include "mLeds.h"
#include "mDelays.h"
#include "mLcd.h"
#include "gIntro.h"
#include "gMenu.h"
#include "gEvent.h"
#include "mSwitch.h"
#include "gGame.h"

void setup();

int main(void)
{	
	GameStatesEnum GameState=kIntro;
	setup();
	for(;;) 
	{	   
		switch(GameState)
		{
		case kIntro:
			gIntro_Show(&GameState);
			break;
		case kMenu:
			gMenu_Show(&GameState);
			break;
		case kGame:
			gGame_Show(&GameState);
			break;
		}
		gEvent_Sw();
	}	
	return 0;
}

void setup()
{
	//mBlinkLed_init();
	mSwitch_Setup();
	mLed_Setup();
	mDelay_Setup();
	EnableInterrupts();
	//mCpu_Setup();
	mLcd_Open();
	mLcd_CreateAllChar();
	gEvent_setup();
}
