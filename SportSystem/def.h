#pragma once

#include "AthleteMap/org_ath_map.h"
#include "Vector_ath/AthVector.h"


//define
#define track1 1;
#define track2 2;
#define race1 -1;
#define race2 -2;

typedef struct
{
	int eventsID;
	int Size;
	Vector Athelte;
	int raceturn;//�����ǵڼ���
	int eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}TrackItem;

typedef struct
{
	int eventsID;
	int Size;
	Vector Athlete;
	int raceturn;//�����ǵڼ���
	int eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}RaceItem;

typedef struct
{
	int minimumNums;//��С������������������ᱻȡ����Ŀ
	int Rankscores[6];//��ͬ������õķ���
}Setting;

//��֯�Ľṹ��
typedef struct
{
	char name[50];
	struct __AMTree* ath_map;
}Organization;

//�������ӱ�
typedef struct
{
	Vector* raceitem1;
	Vector* raceitem2;
	Vector* raceitem3;
	Vector* raceitem4;
}RaceList;

typedef struct
{
	Vector* raceitem1;
	Vector* raceitem2;
	Vector* raceitem3;
	Vector* raceitem4;
}TrackList;
