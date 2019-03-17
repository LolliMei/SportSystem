#pragma once

#include"TrackHashMap/track_item_map.h"
#include"RaceHashMap/race_item_map.h"
#include "AthHashMap/athlete_table.h"
#include "def.h"
#include <stdio.h>
#include <string.h>

void init_Trackitem(track_item_map map)
{
	extern  track_item_map TrackItemTable;
	TrackItem * shotBall;
	TrackItem * highJump;
	TrackItem * broadJump;
	shotBall->eventsID = 201;
	shotBall->startime = 8;
	shotBall->endtime = 8.3;
	highJump->eventsID = 202;
	highJump->startime = 9;
	highJump->endtime = 9.3;
	broadJump->eventsID = 203;
	broadJump->startime = 10;
	broadJump->endtime = 10.3;
	add_track(TrackItemTable, 201, shotBall);
	add_track(TrackItemTable, 202, highJump);
	add_track(TrackItemTable, 203, broadJump);
}

void init_raceitem(race_item_map map)
{
	extern race_item_map RaceItemTable;
	RaceItem *fiftyM;
	RaceItem *oHundredM;
	RaceItem *oThousandM;
	fiftyM->eventsID = 101;
	fiftyM->startime = 8;
	fiftyM->endtime = 8.1;
	oHundredM->eventsID = 102;
	oHundredM->startime = 8.3;
	oHundredM->endtime = 8.5;
	oThousandM->eventsID = 103;
	oThousandM->startime = 9;
	oThousandM->endtime = 9.3;
	add_raceitem(RaceItemTable, 101, fiftyM);
	add_raceitem(RaceItemTable, 102, oHundredM);
	add_raceitem(RaceItemTable, 103, oThousandM);
}

void load_trackitem(track_item_map map,char* filename)
{
	FILE* fp;
	int flag = fopen_s(&fp, filename, "r+");
	assert(flag == 0);
	int size = 0;
	fscanf(fp, "%d#\n", &size);

	for (int i = 0; i < size; i++)
	{
		int eventsID, Size, raceturn, eventplace;
		float starttime, endtime;
		char name[50];
		fscanf_s(fp, "%s", name, 50);
		fscanf(fp, "%d %d %d %d", &eventsID, &Size, &raceturn, &eventplace);
		fscanf(fp, "%f %f", &starttime, &endtime);
		TrackItem* trackitem = (TrackItem*)malloc(sizeof(TrackItem));
		strcpy(trackitem->name, name);
		trackitem->Athlete = init_ath_vector(20);
		trackitem->eventsID = eventsID;
		trackitem->Size = Size;
		trackitem->raceturn = raceturn;
		trackitem->eventplace = eventplace;
		trackitem->startime = starttime;
		trackitem->endtime = endtime;
		add_track(map, trackitem->eventsID, trackitem);
	}
	


	fclose(fp);
}

void load_raceitem(race_item_map map,char* filename)
{
	FILE* fp;
	int flag = fopen_s(&fp, filename, "r+");
	assert(flag == 0);
	int size = 0;
	fscanf(fp, "%d#\n", &size);

	for (int i = 0; i < size; i++)
	{
		int eventsID, Size, raceturn, eventplace;
		float starttime, endtime;
		char name[50];
		fscanf_s(fp, "%s", name, 50);
		fscanf(fp, "%d %d %d %d", &eventsID, &Size, &raceturn, &eventplace);
		fscanf(fp, "%f %f", &starttime, &endtime);
		RaceItem* raceitem = (RaceItem*)malloc(sizeof(RaceItem));
		strcpy(raceitem->name, name);
		raceitem->Athlete = init_ath_vector(20);
		raceitem->eventsID = eventsID;
		raceitem->Size = Size;
		raceitem->raceturn = raceturn;
		raceitem->eventplace = eventplace;
		raceitem->startime = starttime;
		raceitem->endtime = endtime;
		add_raceitem(map, raceitem->eventsID, raceitem);
		//(map, raceitem->eventsID, raceitem);
	}

	fclose(fp);
}
