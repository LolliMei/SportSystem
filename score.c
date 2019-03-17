#include <stdio.h>
#include "scoreRank.h"
#include "SportSystem/def.h"
#include "SportSystem/RaceHashMap/race_item_map.h"
#include "SportSystem/TrackHashMap/track_item_map.h"
#include "SportSystem/AthHashMap/athlete_table.h"
extern Setting setting;

extern race_item_map RaceItemTable;
extern track_item_map TrackItemTable;
extern athlete_table AthHashTable;

int athlete_getscore(){
    
    int itemid;

    RaceItem* race = get_raceitem(RaceItemTable,itemid);

    TrackItem* track = get_trackitem(TrackItemTable,itemid);

	switch(itemid / 100)
	{
		//race
		case 1:
			for (int i = 0; i < race->Athlete->size; i++)
			{
				Athlete* ath = (get_ath_vector_index(race->Athlete, i));
				int score = i >6 ? 0 : setting.Rankscores[i];
				ath->score += score;
			}
		break;
		//track
		case 2:
			for (int i = 0; i < track->Athlete->size; i++)
			{
				Athlete* ath = (get_ath_vector_index(track->Athlete, i));
				const int score = i > 6 ? 0 : setting.Rankscores[i];
				ath->score += score;
			}
		break;

		default :
		exit(0);
		break;
	}

	//针对同一个竞赛项目全部运动员
    for(int i=0;i<setting.getScoreOrder;i++){
		
		race->Athlete[i].data[i]->score += setting.Rankscores[i];
    }
}