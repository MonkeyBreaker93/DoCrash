/*
 * gGame.h
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#ifndef GGAME_H_
#define GGAME_H_

#include "def.h"
#include "gDef.h"

typedef enum
{
	kGameInit,
	kGameRunning,
	kOutOfFuel,
	kCrash,
	kGameQuit,
}GamesStatesEnum;

void gGame_Print(bool amen,bool aVpos);
void gGame_Show(GameStatesEnum *GameState);

#endif /* GGAME_H_ */
