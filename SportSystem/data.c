
#include "Org/org_list.h"
#include "TrackHashMap/track_item_map.h"
#include "../SportSystem/AthleteMap/org_athlete.h"
#include "data.h"
#include "InitTracRaceItem.h"
#include "RaceHashMap/race_item_map.h"
#include "AthHashMap/athlete_table.h"

org_list organization;

race_item_map RaceItemTable;

track_item_map TrackItemTable;

athlete_table AthHashTable;

Setting setting;

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

	//����������Ŀ
	load_raceitem(RaceItemTable, "raceitem.txt");

	//���ؾ�����Ŀ
	load_trackitem(TrackItemTable, "trackitem.txt");

	//���ļ��м�����֯
	load_organization(organization, "organization.txt");

	//���ļ��м������е��˶�Ա
	load_athlete(AthHashTable, "all.txt");





	//���˶�Ա�����Ӧ����֯��
	for (int i = 0; i < AthHashTable->capacity; i++)
	{
		Entry* node = AthHashTable->table[i];
		while(node)
		{
			Athlete* athlete = node->value;
			int orgIndex = atoi(athlete->id) / 100;
			put_org_ath(organization->data[orgIndex].ath_map, atoi(athlete->id), athlete);
			node = node->next;
		}
	}

	load_setting("Setting.txt");
}

void save_athlete(char* filename)
{
	FILE* file;
	int flag = fopen_s(&file, filename, "w");
	assert(flag == 0);
	fprintf(file, "%d#\n", AthHashTable->size);
	for (int i = 0; i < AthHashTable->capacity; i++)
	{
		Entry* entry = AthHashTable->table[i];
		while(entry)
		{
			Athlete* current = entry->value;
			fprintf_s(file, "%s %s %s ", current->id, current->name, current->organization);

			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					fprintf(file, "%d ", current->events[j][k]);
				}
			}
			fprintf(file,"\n");
			entry = entry->next;
		}
	}
	fclose(file);
}

void load_athlete(athlete_table map, char* filename)
{
	FILE* vectorFile;
	int flag = fopen_s(&vectorFile, filename, "r+");
	assert(flag == 0);
	int size;
	fscanf(vectorFile, "%d#\n", &size);

	for (int i = 0; i < size; i++)
	{
		Athlete* ath = (Athlete*)malloc(sizeof(Athlete));
		char id[30];
		char name[30];
		char org[30];
		fscanf(vectorFile, "%s%s%s", id, name, org);
		strcpy(ath->id, id);
		strcpy(ath->name, name);
		strcpy(ath->organization, org);
		//��ȡid
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 2; j++)
			{
				int val;
				fscanf_s(vectorFile, "%d", &val);
				ath->events[k][j] = val;
				//fprintf_s(vectorFile, "%d,", vector->data[i].events[i][j]);
			}
		}
		add_athlete(map, atoi(ath->id), ath);
		init_atl_eve(ath->events, ath);
	}
	fclose(vectorFile);
}

void save_organization(org_list table, char* filename)
{
	FILE* fp = fopen(filename, "w+");
	for (size_t i = 1; i <= 8; i++)
	{
		fprintf(fp, "%s %d\n", table->data[i].name,table->data[i].next_id);
	}
	fclose(fp);
}

void load_organization(org_list table, char* filename)
{
	FILE* fp;
	int flag = fopen_s(&fp, filename, "r+");
	for (size_t i = 1; i <= 8; i++)
	{
		char name[50];
		int next_id;
		fscanf(fp, "%s %d\n", name,&next_id);
		strcpy(table->data[i].name, name);
		//TODO::�±�ת����������֯
		table->data->next_id = next_id;
	}
	fclose(fp);
}

void load_setting(char* filename)
{
	FILE* fp;
	int flag = fopen_s(&fp, filename, "r+");
	assert(flag == 0);
	fscanf(fp,"%d\n",&setting.minimumNums);
	for(size_t i = 0; i < 6; i++)
	{
		fscanf(fp,"%d",&setting.Rankscores[i]) ;
	}
	fclose(fp);

}

void save_setting(char* filename)
{
	FILE* fp;
	int flag = fopen_s(&fp, filename, "w+");
	assert(flag == 0);
	fprintf(fp,"%d\n",setting.minimumNums);
	for(size_t i = 0; i < 6; i++)
	{
		fprintf(fp,"%d",setting.Rankscores[i]) ;
	}
	fclose(fp);
}

 
