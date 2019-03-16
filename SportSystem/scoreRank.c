#include "../SportSystem/RaceHashMap/race_item_map.h"
#include "../SportSystem/TrackHashMap/track_item_map.h"

extern race_item_map RaceItemTable;
extern track_item_map TrackItemTable;

int TrackScoreRank()
{
	TrackItem* shotBall;
	TrackItem* highJump;
	TrackItem* boardJump;
	Athlete temp;
	Athlete Athlete1;
	Athlete Athlete2;
	shotBall = get_trackitem(TrackItemTable, 201);
	highJump = get_trackitem(TrackItemTable, 202);
	boardJump = get_trackitem(TrackItemTable, 203);
	for (size_t i = 0; i < shotBall->Athlete->size-1; i++)
	{
		for (size_t j = 0; j <shotBall->Athlete->size - 1-i; j++)
		{
			Athlete1=get_ath_vector_index(shotBall->Athlete,j);
			Athlete2 = get_ath_vector_index(shotBall->Athlete, j + 1);

			int score2 = get_Ath_Event_score(get_ath_vector_index(shotBall->Athlete, j + 1), 201);
			if (get_Ath_Event_score(Athlete1,201)<get_Ath_Event_score(Athlete2,201))
			{
				set_ath_vector_index(shotBall->Athlete, j, Athlete2);
				set_ath_vector_index(shotBall->Athlete, j + 1, Athlete1);
			}
		}
	}
	
}
int get_Ath_Event_score(Athlete ath, int eveID)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (ath.events[i][0] == eveID)
			return ath.events[i][1];
	}
}
