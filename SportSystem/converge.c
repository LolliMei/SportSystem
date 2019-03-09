#include <stdio.h>
#include "converger.h"
#include <stdlib.h>
#include "../SportSystem/Org/OrgTable.h"
#include "../SportSystem/AthleteMap/org_ath_map.h"
#include <string.h>

extern OrgTable organization;



void InitAthlete(){
	char id[20], name[30];
	int i;
	scanf("%s",&id);
	scanf("%s", &name);
	i = atoi(id);

	switch (i / 100) {
		case 1:	
		{
			Athlete* athlete = init_athlete(id, name, "AB");
			AthMapPut(organization->data[1].ath_map, athlete->id, athlete);
		}
		break;
		case 2:	
		{
			Athlete* athlete = init_athlete(id, name, "CD");
			AthMapPut(organization->data[2].ath_map, athlete->id, athlete);
		}
			break;
		case 3:	
		{
			Athlete* athlete = init_athlete(id, name, "EF");
			AthMapPut(organization->data[3].ath_map, athlete->id, athlete);
		}
			break;
		case 4:
		{	
			Athlete* athlete = init_athlete(id, name, "G");
			AthMapPut(organization->data[4].ath_map, athlete->id, athlete);
		}
			break;
		case 5:
		{
			Athlete* athlete = init_athlete(id, name, "至诚");
			AthMapPut(organization->data[5].ath_map, athlete->id, athlete);
		}
			break;
		case 6:
		{
			Athlete* athlete = init_athlete(id, name, "知行");
			AthMapPut(organization->data[6].ath_map, athlete->id, athlete);
		}
			break;
		case 7:	
		{
			Athlete* athlete = init_athlete(id, name, "思源");
			AthMapPut(organization->data[7].ath_map, athlete->id, athlete);
		}
			break;
		case 8:	
		{
			Athlete* athlete = init_athlete(id, name, "弘毅");
			AthMapPut(organization->data[8].ath_map, athlete->id, athlete);
		}
			break;
	}


}