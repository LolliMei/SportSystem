#include "def.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "AthHashMap/AthleteTable.h"
#include <string.h>

void save_athlete(AthVector vector, char* filename)
{
	FILE* vectorFile;
	int flag = fopen_s(&vectorFile, filename, "w+");
	assert(flag == 0);
	fprintf_s(vectorFile, "%d#\n", vector->size);
	for (int i = 0; i < vector->size; i++)
	{
		//写入ID，名字，组织名	
		fprintf_s(vectorFile, "%s,%s,%s,", vector->data[i].id, vector->data[i].name, vector->data[i].organization);
		//写入eventsid
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				fprintf_s(vectorFile, "%d,", vector->data[i].events[i][j]);
			}
		}
		//每个运动员信息占一行
		fprintf_s(vectorFile, "\n");
	}
	fflush(vectorFile);
	fclose(vectorFile);
}

void load_athlete(AthHashMap map, char* filename)
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
		fscanf(vectorFile, "%s,%s,%s", id, name, org);
		strcpy(ath->id, id);
		strcpy(ath->name, name);
		strcpy(ath->organization, org);
		//读取id
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int val;
				fscanf(vectorFile, "%d,", &val);
				ath->events[i][j] = val;
				//fprintf_s(vectorFile, "%d,", vector->data[i].events[i][j]);
			}
		}
		add_athlete(map, atoi(ath->id), ath);
	}

	fclose(vectorFile);
}

