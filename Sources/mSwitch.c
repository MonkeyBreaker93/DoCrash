/*
 * mSwitch.c
 *
 *  Created on: Oct 3, 2014
 *      Author: julian.burellap
 */

#include "mSwitch.h"
#include "iDio.h"


bool mSwitch_ReadSwitch(SwitchEnum aSwitchNb)
{
	switch(aSwitchNb)
	{
	case kSw1:
		return iDio_GetPort(kPortB,kBit18);
		break;
	case kSw2:
		return iDio_GetPort(kPortB,kBit19);
		break;
	case kSw3:
		return iDio_GetPort(kPortC,kBit0);
		break;
	case kSw4:
		return iDio_GetPort(kPortC,kBit4);
		break;
	case kSw5:
		return iDio_GetPort(kPortC,kBit6);
		break;
	case kSw6:
		return iDio_GetPort(kPortC,kBit7);
		break;
	case kSw7:
		return iDio_GetPort(kPortC,kBit10);
		break;
	case kSw8:
		return iDio_GetPort(kPortC,kBit11);
		break;
	default: return 0;
	}
}


bool mSwitch_ReadPushBut(PushButEnum aPushButNb)
{
	bool aState=false;
	switch(aPushButNb)
	{
	case kPushButSW1:
		aState=iDio_GetPort(kPortD,kBit5);
		break;
	case kPushButSW2:
		aState=iDio_GetPort(kPortD,kBit7);
		break;
	case kPushButSW3:
		aState=iDio_GetPort(kPortD,kBit6);
		break;
	case kPushButSW4:
		aState=iDio_GetPort(kPortD,kBit4);
		break;
	}
	return aState;
}

void mSwitch_Setup(void)
{
	iDio_EnablePortClk();
	
	iDio_PinConfig(kPortB, kBit18|kBit19,kGpio);
	iDio_PinConfig(kPortC, kBit0|kBit4|kBit6|kBit7|kBit10|kBit11,kGpio);
	iDio_PinConfig(kPortD, kBit4|kBit5|kBit6|kBit7,kGpio);
	
	
	iDio_SetPortDirection(kPortB, kBit18|kBit19,kInput);
	iDio_SetPortDirection(kPortC, kBit0|kBit4|kBit6|kBit7|kBit10|kBit11,kInput);
	iDio_SetPortDirection(kPortD, kBit4|kBit5|kBit6|kBit7,kInput);
}
void mSwitch_EventSetup(PushButEventStruct* ButStruct,PushButEnum aPushButNb)
{
	ButStruct->act=mSwitch_ReadPushBut(aPushButNb);
	ButStruct->old=mSwitch_ReadPushBut(aPushButNb);
	ButStruct->aPushButNb=aPushButNb;
	ButStruct->dtu=false;
	ButStruct->utd=false;
}
void mSwitch_EventMng(PushButEventStruct* ButStruct)
{
	ButStruct->old=ButStruct->act;
	ButStruct->act=mSwitch_ReadPushBut(ButStruct->aPushButNb);
	if((ButStruct->act)&&(!(ButStruct->old)))
		ButStruct->dtu=true;
	if((!(ButStruct->act))&&(ButStruct->old))
		ButStruct->utd=true;
}
