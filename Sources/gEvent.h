/*
 * gEvent.h
 *
 *  Created on: Oct 17, 2014
 *      Author: sebastie.glauser
 */

#ifndef GEVENT_H_
#define GEVENT_H_

typedef struct gEventSWStruct
{
	bool utd;
	bool dtu;
}gEventSWStruct;


typedef struct gEventSWsStruct
{
	struct gEventSWStruct Sw1;
	struct gEventSWStruct Sw2;
	struct gEventSWStruct Sw3;
	struct gEventSWStruct Sw4;

}gEventSWsStruct;
void gEvent_setup();
void gEvent_GetSw(struct gEventSWsStruct *gSW);
void gEvent_Sw();
void gEvent_ResetSw();
#endif /* GEVENT_H_ */
