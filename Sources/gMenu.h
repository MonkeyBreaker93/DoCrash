/*
 * gMenu.h
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#ifndef GMENU_H_
#define GMENU_H_

#include "Def.h"

#include "gDef.h"

typedef enum
{
	kMenuInit,
	kMenuRunning,
	kMenuQuit,
}MenuStatesEnum;

typedef enum
{
	kStartGame,
	kUpgrade,
	kCredit,
}MenuSelectionStatesEnum;


void gMenu_Show(GameStatesEnum *GameState);
void gMenu_PrintMens(bool amen);
void gMenu_Print(bool amen,MenuSelectionStatesEnum aSelectMenu);

#endif /* GMENU_H_ */
