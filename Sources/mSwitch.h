/*
 * mSwitch.h
 *
 *  Created on: Oct 3, 2014
 *      Author: julian.burellap
 */

#ifndef MSWITCH_H_
#define MSWITCH_H_

#include "def.h"

typedef enum
{
	kSw1=0x01,
	kSw2=0x02,
	kSw3=0x04,
	kSw4=0x08,
	kSw5=0x10,
	kSw6=0x20,
	kSw7=0x40,
	kSw8=0x80
}SwitchEnum;

typedef enum
{
	kPushButSW1=0x01,
	kPushButSW2=0x02,
	kPushButSW3=0x04,
	kPushButSW4=0x08
}PushButEnum;

typedef struct PushButEventStruct
{
	bool old;
	bool act;
	bool utd;
	bool dtu;
	PushButEnum aPushButNb;
}PushButEventStruct;

void mSwitch_Setup(void);

bool mSwitch_ReadSwitch(SwitchEnum aSwitchNb);
bool mSwitch_ReadPushBut(PushButEnum aPushButNb);
void mSwitch_EventSetup(PushButEventStruct* ButStruct,PushButEnum aPushButNb);
void mSwitch_EventMng(PushButEventStruct* ButStruct);

#endif /* MSWITCH_H_ */
