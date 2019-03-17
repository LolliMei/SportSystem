#pragma once

#include "AthleteMap/org_athlete.h"
#include "Vector_ath/item_athlete.h"


//define
#define track1 1;
#define track2 2;
#define race1 -1;
#define race2 -2;

typedef struct
{
	char name[50];
	int eventsID;
	int Size;
	item_athlete Athlete;
	int raceturn;//�����ǵڼ���
	int eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}TrackItem;

typedef struct
{
	char name[50];
	int eventsID;
	int Size;
	item_athlete Athlete;
	int raceturn;//�����ǵڼ���
	int eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}RaceItem;

typedef struct
{
	int minimumNums;//��С������������������ᱻȡ����Ŀ
	int Rankscores[6];//��ͬ������õķ���
	int getScoreOrder;
}Setting;

//��֯�Ľṹ��
typedef struct
{
	char name[50];
	int next_id;
	struct __AMTree* ath_map;
}Organization;

//�������ӱ�
typedef struct
{
	item_athlete* raceitem1;
	item_athlete* raceitem2;
	item_athlete* raceitem3;
	item_athlete* raceitem4;
}RaceList;

typedef struct
{
	item_athlete* raceitem1;
	item_athlete* raceitem2;
	item_athlete* raceitem3;
	item_athlete* raceitem4;
}TrackList;
