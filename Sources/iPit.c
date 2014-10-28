/*
------------------------------------------------------------
Copyright 2003-2014 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : iPit.c
Auteur et Date : Glauser Sébastien
Description dans le fichier iPit.h
------------------------------------------------------------
 */

#include "iPit.h"
#include "def.h"

static struct DelayStruct sDelayTab[kNbOfDelay];

void iPit_InitDelay()
{
	int aIndex;
	for(aIndex=0;aIndex<kNbOfDelay;aIndex++)
	{
		sDelayTab[aIndex].Counter=0;
		sDelayTab[aIndex].IsDone=FALSE;
		sDelayTab[aIndex].IsFree=true;
	}
}

int iPit_GetDelay(unsigned int aCount)
{
	int aIndex;
	for(aIndex=0;aIndex<kNbOfDelay;aIndex++)
	{
		if(sDelayTab[aIndex].IsFree==true)
		{
			sDelayTab[aIndex].IsFree=false;
			sDelayTab[aIndex].Counter=aCount;
			return aIndex;
		}
	}
	return -1;
}

void iPit_DelayRelease(int aIndex)
{
	sDelayTab[aIndex].Counter=0;
	sDelayTab[aIndex].IsDone=FALSE;
	sDelayTab[aIndex].IsFree=true;
}

bool iPit_IsDelayDone(int aIndex)
{
	return sDelayTab[aIndex].IsDone;
}

void iPit_Config(unsigned long aPit0_LDVAL,unsigned long aPit1_LDVAL)
{
	unsigned long* SIM_SCGC6   = (unsigned long*) 0x4004803C;
	unsigned long* aPIT_MCR    = (unsigned long*) 0x40037000;
	unsigned long* aPIT_LDVAL0 = (unsigned long*) 0x40037100;
	unsigned long* aPIT_LDVAL1 = (unsigned long*) 0x40037110;
	unsigned long* aPIT_TCTRL0 = (unsigned long*) 0x40037108;
	unsigned long* aPIT_TCTRL1 = (unsigned long*) 0x40037118;
	unsigned long* aNVIC_ISER  = (unsigned long*) 0xE000E100;
	unsigned long* aNVIC_IPR5  = (unsigned long*) 0xE000E414;


	//SIM_SCG6 found at p216
	*SIM_SCGC6 |= (0x01<<23);
	// Clear MDIS and FRZ in PIT_MCR's register
	*aPIT_MCR &=~0b00000010;
	// Set MDIS=0 and FRZ=1 in PIT_MCR's register
	*aPIT_MCR |= 0b00000001;

	/*1ms and 10ms
	aPIT_LDVAL0 = 0x1f40;
	aPIT_LDVAL1 = 0x13880;*/

	// 1ms and 10ms
	*aPIT_LDVAL0 = aPit0_LDVAL;
	*aPIT_LDVAL1 = aPit1_LDVAL;

	// Set TIE PIT0&1
	*aPIT_TCTRL0|= 0b010;
	*aPIT_TCTRL1|= 0b010;

	*aNVIC_ISER |= (0b01<<22);
	*aNVIC_IPR5 |= (0b11<<22);
}


void iPit_StrartPit(PitEnum kSelect)
{
	unsigned long* aPIT_TCTRL0 = (unsigned long*) 0x40037108;
	unsigned long* aPIT_TCTRL1 = (unsigned long*) 0x40037118;
	// Set TIE PIT0&1
	if((kSelect&kPit0)==1)
		*aPIT_TCTRL0|= 0b001;
	if((kSelect&kPit1)==1)
		*aPIT_TCTRL1|= 0b001;
}

void iPit_INTPit()
{
	unsigned long* aPIT_TFLG0 = (unsigned long*) 0x4003710C;
	unsigned long* aPIT_TFLG1 = (unsigned long*) 0x4003711C;
	if(((*aPIT_TFLG0)&0b01)==0b01)
	{
		int aIndex;
		*aPIT_TFLG0|=0b01;
		for(aIndex=0;aIndex<kNbOfDelay;aIndex++)
		{
			if(sDelayTab[aIndex].IsFree==false)
			{
				if(sDelayTab[aIndex].Counter<1)
				{
					sDelayTab[aIndex].IsDone=true;
				}
				else
				{
					sDelayTab[aIndex].Counter--;
				}
			}
		}
	}
	if(((*aPIT_TFLG1)&0b01)==0b01)
	{
		*aPIT_TFLG1 |= 0b01;
	}
}
