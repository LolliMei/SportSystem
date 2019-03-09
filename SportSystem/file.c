#include "def.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>

void save_vector(Vector vector, char* filename)
{
	FILE* vectorFile;
	int flag = fopen_s(&vectorFile, filename, "w+");
	assert(flag != -1);
	for (size_t i = 0; i < vector->size; i++)
	{
		fprintf_s(vectorFile, "%d#", VectorGet(vector, i));
	}
	fflush(vectorFile);
	fclose(vectorFile);
}

void load_vector(Vector vector, char* filename)
{
	FILE* vectorFile;
	int flag = fopen_s(&vectorFile, filename, "r+");
	assert(flag != -1);
	for (size_t i = 0; i < vector->size; i++)
	{
		int data;
		fscanf_s(vectorFile, "%d#", &data);
			VectorAddLast(vector, data);
	}
	fflush(vectorFile);
	fclose(vectorFile);

}

char* save_athlete(Athlete ath)
{
	char* str = (char*)malloc(sizeof(char) * 200);
	sprintf_s(str, 200, "%d@%s@%s@%s", ath.id, 20, ath.name, 20, ath.organization, 30, ath.events, 30);
	return str;
}

