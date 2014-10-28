/*
Copyright 2003-2014 Haute Ecole ARC Ing�nierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : iPit.h
Auteur et Date : Glauser S�bastien
But :
Modifications
Date Faite Ctrl Description
------------------------------------------------------------
*/


#ifndef IPIT_H_
#define IPIT_H_

#include "def.h"

#define kNbOfDelay 10

struct DelayStruct
{
	unsigned int Counter; // La valeur du delay d�sir�
	bool IsFree ; // Le delay est d�j� utilis�?
	bool IsDone ; // Le delay est �chu?
};

typedef enum
{
	kPit0=0x01,
	kPit1=0x10
}PitEnum;

void iPit_Config(unsigned long aPit0_LDVAL,unsigned long aPit1_LDVAL);
void iPit_StrartPit(PitEnum kSelect);
void iPit_INTPit();
void iPit_InitDelay();
int iPit_GetDelay(unsigned int aCount);
void iPit_DelayRelease(int aIndex);
bool iPit_IsDelayDone(int aIndex);

#endif /* IPIT_H_ */
