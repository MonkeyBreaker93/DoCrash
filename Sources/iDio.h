/*
 * iDio.h
 *
 *  Created on: Oct 3, 2014
 *      Author: julian.burellap
 */

#ifndef IDIO_H_
#define IDIO_H_

#include "def.h"

typedef enum
{
	kPortA,
	kPortB,
	kPortC,
	kPortD,
	kPortE
}PortIOEnum;

typedef enum
{
	kPin0=0x01,
	kPin1=0x02,
	kPin2=0x04,
	kPin3=0x08,
	kPin4=0x10,
	kPin5=0x20,
	kPin6=0x40,
	kPin7=0x80,
	kPin8=0x0100,
	kPin9=0x0200,
	kPin10=0x0400,
	kPin11=0x0800,
	kPin12=0x1000,
	kPin13=0x2000,
	kPin14=0x4000,
	kPin15=0x8000,
	kPin16=0x010000,
	kPin17=0x020000,
	kPin18=0x040000,
	kPin19=0x080000,
	kPin20=0x100000,
	kPin21=0x200000,
	kPin22=0x400000,
	kPin23=0x800000,
	kPin24=0x01000000,
	kPin25=0x02000000,
	kPin26=0x04000000,
	kPin27=0x08000000,
	kPin28=0x10000000,
	kPin29=0x20000000,
	kPin30=0x40000000,
	kPin31=0x80000000
}PinNbEnum;

typedef enum
{
	kDisable,
	kGpio,
	kAlt2,
	kAlt3,
	kAlt4,
	kAlt5,
	kAlt6,
	kAlt7
}PinFunctionEnum;

typedef enum
{
	kBit0=0x01,
	kBit1=0x02,
	kBit2=0x04,
	kBit3=0x08,
	kBit4=0x10,
	kBit5=0x20,
	kBit6=0x40,
	kBit7=0x80,
	kBit8=0x0100,
	kBit9=0x0200,
	kBit10=0x0400,
	kBit11=0x0800,
	kBit12=0x1000,
	kBit13=0x2000,
	kBit14=0x4000,
	kBit15=0x8000,
	kBit16=0x010000,
	kBit17=0x020000,
	kBit18=0x040000,
	kBit19=0x080000,
	kBit20=0x100000,
	kBit21=0x200000,
	kBit22=0x400000,
	kBit23=0x800000,
	kBit24=0x01000000,
	kBit25=0x02000000,
	kBit26=0x04000000,
	kBit27=0x08000000,
	kBit28=0x10000000,
	kBit29=0x20000000,
	kBit30=0x40000000,
	kBit31=0x80000000
}IoMaskEnum;

typedef enum
{
	kInput,
	kOutput
}IoDirectionEnum;

typedef enum
{
	kOff,
	kOn
}IoStateEnum;


typedef IoStateEnum LedStateEnum;

void iDio_EnablePortClk(void);
void iDio_PinConfig(PortIOEnum aPort,PinNbEnum aPinNb,PinFunctionEnum aPinFunc);
void iDio_SetPortDirection(PortIOEnum aPort, IoMaskEnum aMask, IoDirectionEnum aDir);
void iDio_SetPort(PortIOEnum aPort, IoMaskEnum aMask,IoStateEnum aState);
bool iDio_GetPort(PortIOEnum aPort, IoMaskEnum aMask);
void iDio_PortLcd(byte aData);

#endif /* IDIO_H_ */
