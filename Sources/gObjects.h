/*
 * gObjects.h
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#ifndef GOBJECTS_H_
#define GOBJECTS_H_

#include "def.h"

struct gObject
{
	bool free;
	bool posy;
	int  posx;
};


void gObjects_CreateMens();
void gObjects_CreateTals();
void gObjects_CreateFuels();
void gObjects_PrintMen(bool amen);
void gObjects_PrintTal();
void gObjects_PrintFuel();
void gObjects_ReleaseMen(int aIndex);
void gObjects_ReleaseTal(int aIndex);
int  gObjects_CreateMen(bool posy, int posx);
void gObjects_CreateFuel(bool posy, int posx);
int  gObjects_CreateTal(bool posy, int posx);
void gObjects_Init();
int  gObjects_MoveMen(bool aVpos);
bool gObjects_MoveTal(bool aVpos);
bool gObjects_MoveFuel(bool aVpos);


#endif /* GOBJECTS_H_ */
