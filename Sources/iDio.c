/*
Copyright 2003-2014 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : iDio.c
Auteur et Date : Glauser Sébastien
But :
Modifications
Date Faite Ctrl Description
------------------------------------------------------------
*/


#include "iDio.h"
#include <MKL46Z4.h>
#include "def.h"


void iDio_EnablePortClk(void)
{
	unsigned long* aSystemClockControl = (unsigned long*) 0x40048038;
	*aSystemClockControl |= 0x00003E00;
}

void iDio_PinConfig(PortIOEnum aPort,PinNbEnum aPinNb,PinFunctionEnum aPinFunc)
{
	int i;
	unsigned long* aPortAPtr = (unsigned long*) 0x40049000;
	unsigned long* aPortBPtr = (unsigned long*) 0x4004A000;
	unsigned long* aPortCPtr = (unsigned long*) 0x4004B000;
	unsigned long* aPortDPtr = (unsigned long*) 0x4004C000;
	unsigned long* aPortEPtr = (unsigned long*) 0x4004D000;
	
	switch(aPort)
	{
	case kPortA:	
		for(i=0; i<32; i++)
			if(aPinNb&(1<<i))
			{
				aPortAPtr[i] &= ~(0x111<<8);
				aPortAPtr[i] |= (aPinFunc<<8);
			}
		aPortAPtr[4] = 0x00000105; // MUX 001; SRE 1; PE 0; PS 1
		break;
	case kPortB:	
		for(i=0; i<32; i++)
			if(aPinNb&(1<<i))
			{
				aPortBPtr[i] &= ~(0x111<<8);
				aPortBPtr[i] |= (aPinFunc<<8);
			}	
		break;
	case kPortC:
		for(i=0; i<32; i++)
			if(aPinNb&(1<<i))
			{
				aPortCPtr[i] &= ~(0x111<<8);
				aPortCPtr[i] |= (aPinFunc<<8);
			}
		break;
	case kPortD:
		for(i=0; i<32; i++)
			if(aPinNb&(1<<i))
			{
				aPortDPtr[i] &= ~(0x111<<8);
				aPortDPtr[i] |= (aPinFunc<<8);
			}
		break;
	case kPortE:
		for(i=0; i<32; i++)
			if(aPinNb&(1<<i))
			{
				aPortEPtr[i] &= ~(0x111<<8);
				aPortEPtr[i] |= (aPinFunc<<8);
			}
		break;
	default: return;
	}
}

void iDio_SetPortDirection(PortIOEnum aPort, IoMaskEnum aMask, IoDirectionEnum aDir)
{
	unsigned long* aTrisAPtr = (unsigned long*) 0x400FF014;
	unsigned long* aTrisBPtr = (unsigned long*) 0x400FF054;
	unsigned long* aTrisCPtr = (unsigned long*) 0x400FF094;
	unsigned long* aTrisDPtr = (unsigned long*) 0x400FF0D4;
	unsigned long* aTrisEPtr = (unsigned long*) 0x400FF114;
	
	switch(aPort)
	{
	case kPortA:
		if(aDir)//Output
			*aTrisAPtr |= aMask;
		else//Input
			*aTrisAPtr &= ~aMask;
		break;
	case kPortB:	
		if(aDir)//Output
			*aTrisBPtr |= aMask;
		else//Input
			*aTrisBPtr &= ~aMask;	
		break;
	case kPortC:
		if(aDir)//Output
			*aTrisCPtr |= aMask;
		else//Input
			*aTrisCPtr &= ~aMask;
		break;
	case kPortD:
		if(aDir)//Output
			*aTrisDPtr |= aMask;
		else//Input
			*aTrisDPtr &= ~aMask;
		break;
	case kPortE:
		if(aDir)//Output
			*aTrisEPtr |= aMask;
		else//Input
			*aTrisEPtr &= ~aMask;
		break;
	default: return;
	}
}

void iDio_SetPort(PortIOEnum aPort, IoMaskEnum aMask,IoStateEnum aState)
{
	unsigned long* aPortADataOutPtr = (unsigned long*) 0x400FF000;
	unsigned long* aPortBDataOutPtr = (unsigned long*) 0x400FF040;
	unsigned long* aPortCDataOutPtr = (unsigned long*) 0x400FF080;
	unsigned long* aPortDDataOutPtr = (unsigned long*) 0x400FF0C0;
	unsigned long* aPortEDataOutPtr = (unsigned long*) 0x400FF100;
	
	switch(aPort)
	{
	case kPortA:		
		if(aState)//1
			*aPortADataOutPtr |= aMask;
		else//0
			*aPortADataOutPtr &= ~aMask;
		break;
	case kPortB:		
		if(aState)//1
			*aPortBDataOutPtr |= aMask;
		else//0
			*aPortBDataOutPtr &= ~aMask;	
		break;
	case kPortC:	
		if(aState)//1
			*aPortCDataOutPtr |= aMask;
		else//0
			*aPortCDataOutPtr &= ~aMask;
		break;
	case kPortD:
		if(aState)//1
			*aPortDDataOutPtr |= aMask;
		else//0
			*aPortDDataOutPtr &= ~aMask;
		break;
	case kPortE:
		if(aState)//1
			*aPortEDataOutPtr |= aMask;
		else//0
			*aPortEDataOutPtr &= ~aMask;
		break;
	default: return;
	}
}

bool iDio_GetPort(PortIOEnum aPort, IoMaskEnum aMask)
{
	unsigned long* aPortADataInPtr = (unsigned long*) 0x400FF010;
	unsigned long* aPortBDataInPtr = (unsigned long*) 0x400FF050;
	unsigned long* aPortCDataInPtr = (unsigned long*) 0x400FF090;
	unsigned long* aPortDDataInPtr = (unsigned long*) 0x400FF0D0;
	unsigned long* aPortEDataInPtr = (unsigned long*) 0x400FF110;
	
	switch(aPort)
	{
	case kPortA:
		return (*aPortADataInPtr)&aMask;
		break;
	case kPortB:
		return (*aPortBDataInPtr)&aMask;	
		break;
	case kPortC:
		return (*aPortCDataInPtr)&aMask;
		break;
	case kPortD:
		return (*aPortDDataInPtr)&aMask;
		break;
	case kPortE:
		return (*aPortEDataInPtr)&aMask;
		break;
	default: return FALSE;
	}
}

void iDio_PortLcd(byte aData)
{
	ByteUnion aDataByteUnion;
	aDataByteUnion.Byte=aData;
	iDio_SetPort(kPortB,kPin20,aDataByteUnion.Bits.b0);
	iDio_SetPort(kPortE,kPin21,aDataByteUnion.Bits.b1);
	iDio_SetPort(kPortE,kPin20,aDataByteUnion.Bits.b2);
	iDio_SetPort(kPortE,kPin2,aDataByteUnion.Bits.b3);
	iDio_SetPort(kPortE,kPin3,aDataByteUnion.Bits.b4);
	iDio_SetPort(kPortE,kPin6,aDataByteUnion.Bits.b5);
	iDio_SetPort(kPortE,kPin18,aDataByteUnion.Bits.b6);
	iDio_SetPort(kPortE,kPin19,aDataByteUnion.Bits.b7);
}
