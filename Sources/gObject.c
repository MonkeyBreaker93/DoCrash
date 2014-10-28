/*
 * gObject.c
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#include "gObjects.h"
#include "def.h"
#include "mLcd.h"
#include <cstdlib>

struct gObject aMen[10];

struct gObject aTal[5];

struct gObject aFuel;

void gObjects_Init()
{
	int aIndex;
	for(aIndex=0;aIndex<10;aIndex++)
	{
		aMen[aIndex].free=true;
		aMen[aIndex].posy=0;
		aMen[aIndex].posx=0;
	}
	for(aIndex=0;aIndex<10;aIndex++)
	{
		aTal[aIndex].free=true;
		aTal[aIndex].posy=0;
		aTal[aIndex].posx=0;
	}
	aFuel.free=true;
	aFuel.posy=0;
	aFuel.posx=0;
}

int gObjects_CreateMen(bool posy, int posx)
{
	int aIndex;
	for(aIndex=0;aIndex<10;aIndex++)
	{
		if(aMen[aIndex].free==true)
		{
			aMen[aIndex].free=false;
			aMen[aIndex].posy=posy;
			aMen[aIndex].posx=posx;
			return aIndex;
		}
	}
	return -1;
}

int gObjects_CreateTal(bool posy, int posx)
{
	int aIndex;
	for(aIndex=0;aIndex<5;aIndex++)
	{
		if(aTal[aIndex].free==true)
		{
			aTal[aIndex].free=false;
			aTal[aIndex].posy=posy;
			aTal[aIndex].posx=posx;
			return aIndex;
		}
	}
	return -1;
}

void gObjects_CreateFuel(bool posy, int posx)
{
	if(aFuel.free==true)
	{
		aFuel.free=false;
		aFuel.posy=posy;
		aFuel.posx=posx;
	}
}

void gObjects_ReleaseMen(int aIndex)
{
	aMen[aIndex].free=true;
	aMen[aIndex].posy=0;
	aMen[aIndex].posx=0;
}

void gObjects_ReleaseTal(int aIndex)
{
	aTal[aIndex].free=true;
	aTal[aIndex].posy=0;
	aTal[aIndex].posx=0;
}

int gObjects_MoveMen(bool aVpos)
{
	int aIndex;
	int score=0;
	for(aIndex=0;aIndex<10;aIndex++)
	{
		if(aMen[aIndex].free==false)
		{
			if(aMen[aIndex].posy==aVpos)
			{
				if(aMen[aIndex].posx<3)
				{
					gObjects_ReleaseMen(aIndex);
					score++;
				}
				else
					aMen[aIndex].posx--;
			}
			else
			{
				if(aMen[aIndex].posx<1)
					gObjects_ReleaseMen(aIndex);
				else
					aMen[aIndex].posx--;
			}

		}
	}
	return score;
}

bool gObjects_MoveTal(bool aVpos)
{
	int aIndex;
	bool aEnd=false;
	for(aIndex=0;aIndex<5;aIndex++)
	{
		if(aTal[aIndex].free==false)
		{
			if(aTal[aIndex].posy==aVpos)
			{
				if(aTal[aIndex].posx<3)
				{
					gObjects_ReleaseTal(aIndex);
					aEnd=true;
				}
				else
					aTal[aIndex].posx--;
			}
			else
			{
				if(aTal[aIndex].posx<1)
					gObjects_ReleaseTal(aIndex);
				else
					aTal[aIndex].posx--;
			}

		}
	}
	return aEnd;
}

bool gObjects_MoveFuel(bool aVpos)
{
	bool aEnd=false;
	if(aFuel.free==false)
	{
		if(aFuel.posy==aVpos)
		{
			if(aFuel.posx<3)
			{
				aFuel.free=true;
				aEnd=true;
			}
			else
				aFuel.posx--;
		}
		else
		{
			if(aFuel.posx<1)
				aFuel.free=true;
			else
				aFuel.posx--;
		}

	}

	return aEnd;
}

void gObjects_PrintMen(bool amen)
{
	int aIndex;
	for(aIndex=0;aIndex<10;aIndex++)
	{
		if(aMen[aIndex].free==false)
		{
			if(amen)
			{
				mLcd_Write(5,aMen[aIndex].posy,aMen[aIndex].posx);
			}
			else
			{
				mLcd_Write(6,aMen[aIndex].posy,aMen[aIndex].posx);
			}
		}
	}	
}

void gObjects_PrintFuel()
{
	if(aFuel.free==false)
	{
		mLcd_Write(3,aFuel.posy,aFuel.posx);
	}	
}

void gObjects_PrintTal()
{
	int aIndex;
	for(aIndex=0;aIndex<5;aIndex++)
	{
		if(aTal[aIndex].free==false)
		{
			mLcd_Write(7,aTal[aIndex].posy,aTal[aIndex].posx);
		}
	}	
}

void gObjects_CreateMens()
{
	if(rand()%3==0)
	{
		gObjects_CreateMen(rand()%2, 15);	
	}
}

void gObjects_CreateTals()
{
	if(rand()%5==0)
	{
		int aIndex;
		bool aPosy=rand()%2;
		bool aCanCreate=true;
		for(aIndex=0;aIndex<5;aIndex++)
		{
			if(aTal[aIndex].free==false)
			{
				if((aTal[aIndex].posy!=aPosy)&&(aTal[aIndex].posx>12))
					aCanCreate=false;
			}
		}
		if(aCanCreate)
			gObjects_CreateTal(aPosy, 15);	
	}
}

void gObjects_CreateFuels()
{
	if(rand()%10==0)
	{
		gObjects_CreateFuel(rand()%2, 15);	
	}
}
