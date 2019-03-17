#include "Athlete.h"
#include <stdlib.h>
#include <string.h>
#include "../SportSystem/AthHashMap/athlete_table.h"
#include "../SportSystem/RaceHashMap/race_item_map.h"
#include "../SportSystem/TrackHashMap/track_item_map.h"
#include "../SportSystem/Vector_ath/item_athlete.h"
Athlete* init_athlete(char* id,char* name,char* org)
{
	Athlete* ath = (Athlete*)malloc(sizeof(Athlete));
	strcpy(ath->id, id);
	strcpy(ath->name, name);
	strcpy(ath->organization, org);

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			ath->events[i][j] = -1;
		}
	}
	return ath;

}
extern athlete_table AthHashTable;
extern race_item_map RaceItemTable;
extern track_item_map TrackItemTable;

void init_atl_eve(int * eventarray,int athID)
{
	Athlete * ath;
	RaceItem* race;
	TrackItem* track;
	int i = 0;
	ath= get_athlete(AthHashTable, athID);
	
	for (i = 0; i < 3; i++)
	{
		ath->events[i][0] = eventarray[i];
		if (eventarray[i]/100==1)
		{
			race=get_raceitem(RaceItemTable, eventarray[i]);
			if (race == NULL) continue;

			push_front_ath_vector(race->Athlete, ath);
		}
		else if (eventarray[i] / 100 == 2)
		{
			track = get_trackitem(TrackItemTable, eventarray[i]);
			if (track == NULL) continue;
			push_front_ath_vector(track->Athlete, ath);
		}
	}
}
Athlete* init_events(int athID, int eventsID, int rank)
{
	Athlete * ath;
	ath = get_athlete(AthHashTable, athID);

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2 - 1; j++)
		{
			if (ath->events[i][j] == -1) {
				ath->events[i][j] = eventsID;
				ath->events[i][j + 1] = rank;
			}
		}
	}
	return ath;

}

//输入对应的项目和运动员，返回项目ID在evnetsID数组里的下标
int eventIndex(Athlete* athlete, int eventID)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (athlete->events[i][0] == eventID)
			return i;
	}
}

int inputscore(int eventID)
{
	TrackItem* trItem;
	RaceItem* raItem;
	Athlete athlete;
	int record = -1;
	int index = -1;
	if (eventID<200)
	{
		raItem = get_raceitem(RaceItemTable, eventID);
		for (size_t i = 0; i < raItem->Athlete->size; i++)
		{
			athlete = get_ath_vector_index(raItem->Athlete, i);
			printf("%s %s %s，请输入该运动员的成绩\n", athlete.id, athlete.name, athlete.organization);
			scanf_s("%d", &record);
			index = eventIndex(&athlete, eventID);
			if (index != -1)
			{
				athlete.events[index][1] = record;
			}
			else
			{
				printf("该运动员没有参加此项目");
			}
		}

	}
	else
	{
		trItem = get_trackitem(TrackItemTable, eventID);
		for (size_t i = 0; i < raItem->Athlete->size; i++)
		{
			athlete = get_ath_vector_index(trItem->Athlete, i);
			printf("%s %s %s，请输入该运动员的成绩\n", athlete.id, athlete.name, athlete.organization);
			scanf_s("%d", &record);
			index = eventIndex(&athlete, eventID);
			if (index != -1)
			{
				athlete.events[index][1] = record;
			}
			else
			{
				printf("该运动员没有参加此项目");
			}
		}
	}

}
