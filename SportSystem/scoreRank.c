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
			if (get_Ath_Event_score(Athlete1,201)<get_Ath_Event_score(Athlete2,201))
			{
				set_ath_vector_index(shotBall->Athlete, j, Athlete2);
				set_ath_vector_index(shotBall->Athlete, j + 1, Athlete1);
			}
		}
	}

	for (size_t i = 0; i < highJump->Athlete->size - 1; i++)
	{
		for (size_t j = 0; j <highJump->Athlete->size - 1 - i; j++)
		{
			Athlete1 = get_ath_vector_index(highJump->Athlete, j);
			Athlete2 = get_ath_vector_index(highJump->Athlete, j + 1);
			if (get_Ath_Event_score(Athlete1, 202)<get_Ath_Event_score(Athlete2, 202))
			{
				set_ath_vector_index(highJump->Athlete, j, Athlete2);
				set_ath_vector_index(highJump->Athlete, j + 1, Athlete1);
			}
		}
	}

	for (size_t i = 0; i < boardJump->Athlete->size - 1; i++)
	{
		for (size_t j = 0; j <boardJump->Athlete->size - 1 - i; j++)
		{
			Athlete1 = get_ath_vector_index(boardJump->Athlete, j);
			Athlete2 = get_ath_vector_index(boardJump->Athlete, j + 1);
			if (get_Ath_Event_score(Athlete1, 203)<get_Ath_Event_score(Athlete2, 203))
			{
				set_ath_vector_index(boardJump->Athlete, j, Athlete2);
				set_ath_vector_index(boardJump->Athlete, j + 1, Athlete1);
			}
		}
	}
	return 1;
} 

int RaceScoreRank()
{
	RaceItem *fiftyM;
	RaceItem *oHundredM;
	RaceItem *oThousandM;
	Athlete temp;
	Athlete Athlete1;
	Athlete Athlete2;
	fiftyM = get_raceitem(RaceItemTable, 101);
	oHundredM = get_raceitem(RaceItemTable, 102);
	oThousandM = get_raceitem(RaceItemTable, 103);
	for (size_t i = 0; i < fiftyM->Athlete->size - 1; i++)
	{
		for (size_t j = 0; j <fiftyM->Athlete->size - 1 - i; j++)
		{
			Athlete1 = get_ath_vector_index(fiftyM->Athlete, j);
			Athlete2 = get_ath_vector_index(fiftyM->Athlete, j + 1);
			if (get_Ath_Event_score(Athlete1, 101)>get_Ath_Event_score(Athlete2, 101))
			{
				set_ath_vector_index(fiftyM->Athlete, j, Athlete2);
				set_ath_vector_index(fiftyM->Athlete, j + 1, Athlete1);
			}
		}
	}

	for (size_t i = 0; i < oHundredM->Athlete->size - 1; i++)
	{
		for (size_t j = 0; j <oHundredM->Athlete->size - 1 - i; j++)
		{
			Athlete1 = get_ath_vector_index(oHundredM->Athlete, j);
			Athlete2 = get_ath_vector_index(oHundredM->Athlete, j + 1);

			int score2 = get_Ath_Event_score(get_ath_vector_index(oHundredM->Athlete, j + 1), 102);
			if (get_Ath_Event_score(Athlete1, 102)>get_Ath_Event_score(Athlete2, 102))
			{
				set_ath_vector_index(oHundredM->Athlete, j, Athlete2);
				set_ath_vector_index(oHundredM->Athlete, j + 1, Athlete1);
			}
		}
	}

	for (size_t i = 0; i < oThousandM->Athlete->size - 1; i++)
	{
		for (size_t j = 0; j <oThousandM->Athlete->size - 1 - i; j++)
		{
			Athlete1 = get_ath_vector_index(oThousandM->Athlete, j);
			Athlete2 = get_ath_vector_index(oThousandM->Athlete, j + 1);

			int score2 = get_Ath_Event_score(get_ath_vector_index(oThousandM->Athlete, j + 1), 103);
			if (get_Ath_Event_score(Athlete1, 103)>get_Ath_Event_score(Athlete2, 103))
			{
				set_ath_vector_index(oThousandM->Athlete, j, Athlete2);
				set_ath_vector_index(oThousandM->Athlete, j + 1, Athlete1);
			}
		}
	}
	return 1;
}

int get_Ath_Event_score(Athlete ath, int eveID)					
{
	for (size_t i = 0; i < 3; i++)
	{
		if (ath.events[i][0] == eveID)
			return ath.events[i][1];
	}
	return 1;
}

//成绩为六位，12位为分钟，34位为秒，56位为微秒
void print_Rank(int eventID)
{
	TrackItem* trItem;
	RaceItem* raItem;
	Athlete athlete;
	if (eventID<200)
	{
		raItem = get_raceitem(RaceItemTable, eventID);
		for (size_t i = 0; i < raItem->Athlete->size; i++)
		{
			athlete = get_ath_vector_index(raItem->Athlete, i);
			int score = get_Ath_Event_score(athlete, eventID);
			int min = score / 1000;
			int seconds = (score / 100)%100;
			int microseconds = score % 100;
			printf("%s\t%s\t%s\t%dmin%ds%dms\n",athlete.id,athlete.name,athlete.organization,min,seconds,microseconds);
		}

	}
	else
	{
		trItem = get_trackitem(TrackItemTable, eventID);
		for (size_t i = 0; i < raItem->Athlete->size; i++)
		{
			athlete = get_ath_vector_index(trItem->Athlete, i);
			int score = get_Ath_Event_score(athlete, eventID);
			int m = score / 100;
			int cm = score % 100;
			printf("%s\t%s\t%s\t%dm%dcm\n", athlete.id, athlete.name, athlete.organization, m,cm);
		}
		trItem = get_trackitem(TrackItemTable, eventID);
	}
}

