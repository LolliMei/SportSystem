
#include "Org/OrgTable.h"
#include "RaceHashMap/RaceHashMap.h"
#include "TrackHashMap/TrackHashMap.h"
#include "AthHashMap/AthleteTable.h"
#include "../SportSystem/AthleteMap/org_ath_map.h"
#include "file.h"
#include "data.h"
#include "InitTracRaceItem.h"

OrgTable organization;

RaceItemHashMap RaceItemTable;

TrackHashMap TrackItemTable;

AthHashMap AthHashTable;


void InitData()
{
	organization = InitOrgTable(20);
	for (size_t i = 0; i < 20; i++)
	{
		organization->data[i].ath_map = InitAthMap();
	}
	RaceItemTable = init_raceitem_map(40);
	TrackItemTable = init_track_table(40);
	AthHashTable = init_athlete_table(1000);

	//从文件中加载所有的运动员
	load_athlete(AthHashTable, "all.txt");

	//从文件中加载组织
	load_organization(organization, "organization.txt");

	//加载田赛项目
	load_raceitem(RaceItemTable, "raceitem.txt");

	//加载径赛项目
	load_trackitem(TrackItemTable, "trackitem.txt");

	//把运动员放入对应的组织中
	for (int i = 0; i < AthHashTable->capacity; i++)
	{
		Entry* node = AthHashTable->table[i];
		while(node)
		{
			Athlete* athlete = node->value;
			int orgIndex = atoi(athlete->id) / 100;
			AthMapPut(organization->data[orgIndex].ath_map, atoi(athlete->id), athlete);
			node = node->next;
		}
	}
}




 
