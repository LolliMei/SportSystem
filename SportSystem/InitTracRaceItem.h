#pragma once
#ifndef ATHLETE_H
#define ATHLETE_H
#include"TrackHashMap/TrackHashMap.h"
#include"RaceHashMap/RaceHashMap.h"
#include "def.h"
void init_Trackitem(TrackHashMap map)
{
	extern  TrackItemTable;
	TrackItem * shotBall;
	TrackItem * highJump;
	TrackItem * broadJump;
	shotBall->eventsID = 201;
	highJump->eventsID = 202;
	broadJump->eventsID = 203;
	add_athlete(TrackItemTable, 201, shotBall);
	add_athlete(TrackItemTable, 202, highJump);
	add_athlete(TrackItemTable, 203, broadJump);
}

void init_raceitem(RaceItemHashMap map)
{
	extern RaceItemTable;
	RaceItem *fiftyM;
	RaceItem *oHundredM;
	RaceItem *oThousandM;
	fiftyM->eventsID = 101;
	oHundredM->eventsID = 102;
	oThousandM->eventsID = 103;
	add_raceitem_map(RaceItemTable, 101, fiftyM);
	add_raceitem_map(RaceItemTable, 102, oHundredM);
	add_raceitem_map(RaceItemTable, 103, oThousandM);
}
#endif