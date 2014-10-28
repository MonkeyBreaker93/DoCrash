/*
------------------------------------------------------------
Copyright 2003-2014 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : iCpu.c
Auteur et Date : Glauser Sébastien
Description dans le fichier iCpu.h
------------------------------------------------------------
*/

#include "iCpu.h"

void iCpu_CLKinit(void){
	// MCG memory map p384
	unsigned long* aMCG_C1 = (unsigned long*) 0x40064000;
	unsigned long* aMCG_C2 = (unsigned long*) 0x40064001;
	unsigned long* aMCG_C5 = (unsigned long*) 0x40064004;
	unsigned long* aMCG_C6 = (unsigned long*) 0x40064005;
	unsigned long* aMCG_S  = (unsigned long*) 0x40064006;
	// Set RANGE0=01, HGO0=1 and EREFS0=1 in MGG_C2's register
	*aMCG_C2 |= 0b00011100;
	// Clear RANGE0, HGO0 and EREFS0 in MGG_C2's register
	*aMCG_C2 &=~0b00100000;

	// Set CLKS=10, FRDIV=011 and IREFS=0 in MGG_C1's register
	*aMCG_C1 |= 0b10011000;
	// Clear CLKS, FRDIV and IREFS in MGG_C1's register
	*aMCG_C1 &=~0b01100000;
	// Wait the OSC Initialisation
	while(((*aMCG_S)&0b00000010)==0b00000010);
	// Wait the Internal reference is external clock
	while(((*aMCG_S)&0b00010000)==0b00000000);
	while(((*aMCG_S)&0b00001100)==0b00001000);
	// Set VRDIV=divBy4 in MGG_C5's register
	*aMCG_C5 |= 0b00000011;
	// Clear PRDIV in MGG_C5's register
	*aMCG_C5 &=~0b00011100;
	// Set VDIV0=0 and PLLS=1  in MGG_C6's register
	*aMCG_C6 |= 0b01000000;
	// Clear VDIV0 and PLLS in MGG_C6's register
	*aMCG_C6 &=~0b0001111;
	//Wait the source of PLLS clock is FLL clock
	while(((*aMCG_S)&0b00100000)==0b00100000);
	//Wait the source of PLLS clock is FLL clock
	while(((*aMCG_S)&0b01000000)==0b01000000);
	// Clear CLKS in MGG_C1's register
	*aMCG_C1 &= ~0b1100000;
	// Wait until the source of CPU is PLL
	while(((*aMCG_S)&0b00001100)==0b00001100);

}
