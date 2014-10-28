/*
 * mLcd.h
 *
 *  Created on: Oct 16, 2014
 *      Author: sebastie.glauser
 */

#ifndef MLCD_H_
#define MLCD_H_

#include "def.h"
#include "iDio.h"

// Publics fonctions
void mLcd_Open();


// Privates fonctions
void mLcd_SendLcdCmd(byte aCmd);
void mLcd_SendLcdData(byte aData);
bool mLcd_ReadLcdBusy();
void mLcd_Setup();
void mLcd_WriteEntireDisplay();
void mLcd_gotoxy(unsigned int x, unsigned int y);
void mLcd_Write(char aChar, unsigned int aPos_y,unsigned int aPos_x);
void mLcd_Clear();
void mLcd_CreateChar(char *aArray,unsigned int aIndex);
void mLcd_WriteAt(char *aText, unsigned int aPos_y,unsigned int aPos_x);
void mLcd_CreateAllChar();
void mLcd_CreateMonkey();
#endif /* MLCD_H_ */
