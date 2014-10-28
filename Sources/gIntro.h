/*
 * gIntro.h
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#ifndef GINTRO_H_
#define GINTRO_H_

#include "gDef.h"

typedef enum
{
	kInit,
	kRunning,
	kQuit,
}IntroStatesEnum;

void gIntro_Show(GameStatesEnum *GameState);

#endif /* GINTRO_H_ */
