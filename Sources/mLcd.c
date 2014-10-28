/*
 * mLcd.c
 *
 *  Created on: Oct 16, 2014
 *      Author: sebastie.glauser
 */

#include "def.h"
#include "iDio.h"
#include "mLcd.h"
#include "mDelays.h"
#include "mLcdChar.h"

#define lcd_line_two 0x40 

void mLcd_Setup()
{
	iDio_EnablePortClk();
	iDio_PinConfig(kPortC, kBit13|kBit16,kGpio);
	iDio_PinConfig(kPortE, kBit21|kBit20|kBit2|kBit3|kBit6|kBit18|kBit19,kGpio);
	iDio_PinConfig(kPortB, kBit20|kBit9,kGpio);
	iDio_SetPortDirection(kPortB, kBit20|kBit9,kOutput);
	iDio_SetPortDirection(kPortC, kBit13|kBit16,kOutput);
	iDio_SetPortDirection(kPortE, kBit21|kBit20|kBit2|kBit3|kBit6|kBit18|kBit19,kOutput);
	/*
	iDio_SetPort(kPortC, kBit13,kOff); // Turn RS off
	iDio_SetPort(kPortC, kBit16,kOff); // Turn R/W off
	iDio_SetPort(kPortB, kBit9,kOff); // Turn E off*/
}
void mLcd_SendLcdCmd(byte aCmd)
{
	iDio_SetPort(kPortB, kBit9,kOff);
	iDio_SetPort(kPortC, kBit16,kOff);
	iDio_SetPort(kPortC, kBit13,kOff); 
	iDio_PortLcd(aCmd);
	iDio_SetPort(kPortB, kBit9,kOn);
	iDio_SetPort(kPortB, kBit9,kOff);
	
}
void mLcd_SendLcdData(byte aData)
{
	iDio_SetPort(kPortB, kBit9,kOff);
	iDio_SetPort(kPortC, kBit16,kOff);
	iDio_SetPort(kPortC, kBit13,kOn); 
	iDio_PortLcd(aData);
	iDio_SetPort(kPortB, kBit9,kOn);
	iDio_SetPort(kPortB, kBit9,kOff);
}
bool mLcd_ReadLcdBusy()
{
	bool aBusyFlag;
	iDio_SetPortDirection(kPortE, kBit19,kInput);
	iDio_SetPort(kPortB, kBit9,kOff);
	iDio_SetPort(kPortC, kBit13,kOff); 
	iDio_SetPort(kPortC, kBit16,kOn);
	iDio_SetPort(kPortB, kBit9,kOn);
	aBusyFlag=iDio_GetPort(kPortE, kBit19);
	iDio_SetPort(kPortB, kBit9,kOff);
	iDio_SetPortDirection(kPortE, kBit19,kOutput);
	return aBusyFlag;
	
}
void mLcd_Open()
{
	mLcd_Setup();
	//(Un)comment if you have(n't) already setup the mDelay
	//mDelay_Setup();
	// Initialisation 
	mDelay_ms(16);
	// Set interface 8 bit
	mLcd_SendLcdCmd(0x30);
	mDelay_ms(5);
	mLcd_SendLcdCmd(0x30);
	mDelay_ms(1);
	mLcd_SendLcdCmd(0x30);
	mDelay_ms(1);
	mLcd_SendLcdCmd(0x38);
	mDelay_ms(4);
	// Set Display on cursor off and blink off
	mDelay_ms(4);
	mLcd_SendLcdCmd(0x0C);
	mDelay_ms(4);
	// Clear Display
	mLcd_SendLcdCmd(0x01);
	mDelay_ms(4);
	mLcd_SendLcdCmd(0x06);
	mDelay_ms(4);
}
void mLcd_WriteEntireDisplay(char *aText)
{
	int aPtr=0;
	mLcd_gotoxy(0,0);
	while(aText[aPtr]!=0)
	{
		while(mLcd_ReadLcdBusy());
		mLcd_SendLcdData(aText[aPtr]);
		aPtr++;
	}
}
void mLcd_gotoxy(unsigned int aPos_y,unsigned int aPos_x)
{ 
	while(mLcd_ReadLcdBusy());
	byte address; 
	if(aPos_y != 0) 
		address = lcd_line_two; 
	else 
		address=0; 
	address += aPos_x; 
	mLcd_SendLcdCmd(0x80 | address); 
} 
void mLcd_Write(char aChar, unsigned int aPos_y,unsigned int aPos_x)
{
	mLcd_gotoxy(aPos_y,aPos_x);
	while(mLcd_ReadLcdBusy());
	mLcd_SendLcdData(aChar);
}
void mLcd_Clear()
{
	while(mLcd_ReadLcdBusy());
	mLcd_SendLcdCmd(0x01);
}
void mLcd_WriteAt(char *aText, unsigned int aPos_y,unsigned int aPos_x)
{
	int aPtr=0;
	mLcd_gotoxy(aPos_y,aPos_x);
	while(aText[aPtr]!=0)
	{
		while(mLcd_ReadLcdBusy());
		mLcd_SendLcdData(aText[aPtr]);
		aPtr++;
	}
}
void mLcd_CreateChar(char *aArray,unsigned int aIndex)
{
	while(mLcd_ReadLcdBusy());
	mLcd_SendLcdCmd(0x40| (aIndex<<3));
	int aRow;
	for(aRow=0;aRow<8;aRow++)
	{
		while(mLcd_ReadLcdBusy());
		mLcd_SendLcdData(aArray[aRow]);
	}
	mLcd_gotoxy(0,0);
}
void mLcd_CreateAllChar()
{
	mLcd_CreateChar(chName0,0);
	mLcd_CreateChar(chName1,1);
	mLcd_CreateChar(chName2,2);
	mLcd_CreateChar(chName3,3);
	mLcd_CreateChar(chName4,4);
	mLcd_CreateChar(chName5,5);
	mLcd_CreateChar(chName6,6);
	mLcd_CreateChar(chName7,7);
}

void mLcd_CreateMonkey()
{
	mLcd_CreateChar(chName8,0);
	mLcd_CreateChar(chName9,1);
	mLcd_CreateChar(chName10,2);
	mLcd_CreateChar(chName11,3);
	mLcd_CreateChar(chName12,4);
	mLcd_CreateChar(chName13,5);
}
