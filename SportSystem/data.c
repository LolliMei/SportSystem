
#include "Org/org_list.h"
#include "TrackHashMap/track_item_map.h"
#include "AthHashMap/AthleteTable.h"
#include "../SportSystem/AthleteMap/org_athlete.h"
#include "file.h"
#include "data.h"
#include "InitTracRaceItem.h"
#include "RaceHashMap/race_item_map.h"

org_list organization;

race_item_map RaceItemTable;

track_item_map TrackItemTable;

athlete_table AthHashTable;


void InitData()
{
	organization = init_org_list(20);
	for (size_t i = 0; i < 20; i++)
	{
		organization->data[i].ath_map = InitAthMap();
	}
	RaceItemTable = init_raceitem_map(40);
	TrackItemTable = init_track_table(40);
	AthHashTable = init_athlete_table(1000);

	//���ļ��м������е��˶�Ա
	load_athlete(AthHashTable, "all.txt");

	//���ļ��м�����֯
	load_organization(organization, "organization.txt");

	//����������Ŀ
	load_raceitem(RaceItemTable, "raceitem.txt");

	//���ؾ�����Ŀ
	load_trackitem(TrackItemTable, "trackitem.txt");

	//���˶�Ա�����Ӧ����֯��
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




 
