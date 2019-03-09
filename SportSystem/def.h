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
	int raceturn;//区别是第几轮
	int eventplace;//使用的场地
	float startime;//开始时间
	float endtime;//结束时间
}TrackItem;

typedef struct
{
	int eventsID;
	int Size;
	Vector Athlete;
	int raceturn;//区别是第几轮
	int eventplace;//使用的场地
	float startime;//开始时间
	float endtime;//结束时间
}RaceItem;

typedef struct
{
	int minimumNums;//最小参赛人数，低于这个会被取消项目
	int Rankscores[6];//不同排名获得的分数
}Setting;

//组织的结构体
typedef struct
{
	char name[50];
	struct __AMTree* ath_map;
}Organization;

//田赛连接表
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
