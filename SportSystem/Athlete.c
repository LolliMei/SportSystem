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
			race=get_raceitem(RaceItemTable, eventarray);
			push_front_ath_vector(race->Athlete, *ath);
		}
		else if (eventarray[i] / 100 == 2)
		{
			track = get_trackitem(TrackItemTable, eventarray);
			push_front_ath_vector(track->Athlete, *ath);
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
