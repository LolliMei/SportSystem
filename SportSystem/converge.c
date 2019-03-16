#include <stdio.h>
#include "converger.h"
#include <stdlib.h>
#include "../SportSystem/Org/org_list.h"
#include "../SportSystem/AthleteMap/org_athlete.h"
#include <string.h>

extern org_list organization;

void InitAthlete(int ID){
	char id[20], name[30];
	int i;
	scanf("%s",&id);
	scanf("%s", &name);
	i = atoi(id);

	switch (i / 100) {
		case 1:	
		{
			Athlete* athlete = init_athlete(id, name, "AB");
			put_org_ath(organization->data[1].ath_map, athlete->id, athlete);
		}
		break;
		case 2:	
		{
			Athlete* athlete = init_athlete(id, name, "CD");
			put_org_ath(organization->data[2].ath_map, athlete->id, athlete);
		}
			break;
		case 3:	
		{
			Athlete* athlete = init_athlete(id, name, "EF");
			put_org_ath(organization->data[3].ath_map, athlete->id, athlete);
		}
			break;
		case 4:
		{	
			Athlete* athlete = init_athlete(id, name, "G");
			put_org_ath(organization->data[4].ath_map, athlete->id, athlete);
		}
			break;
		case 5:
		{
			Athlete* athlete = init_athlete(id, name, "至诚");
			put_org_ath(organization->data[5].ath_map, athlete->id, athlete);
		}
			break;
		case 6:
		{
			Athlete* athlete = init_athlete(id, name, "知行");
			put_org_ath(organization->data[6].ath_map, athlete->id, athlete);
		}
			break;
		case 7:	
		{
			Athlete* athlete = init_athlete(id, name, "思源");
			put_org_ath(organization->data[7].ath_map, athlete->id, athlete);
		}
			break;
		case 8:	
		{
			Athlete* athlete = init_athlete(id, name, "弘毅");
			put_org_ath(organization->data[8].ath_map, athlete->id, athlete);
		}
			break;
	}

}

