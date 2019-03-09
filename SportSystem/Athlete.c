#include "Athlete.h"
#include <stdlib.h>
#include <string.h>
#include "../SportSystem/AthHashMap/AthleteTable.h"
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
extern AthHashTable;
void init_atl_eve(int * eventarray,int athID)
{
	Athlete * ath;
	int i = 0;
	ath= get_athlete(AthHashTable, athID);
	for (i = 0; i < 3; i++)
	{
		ath->events[i][0] = eventarray[i];
	}
}
