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
	int raceturn;//区别是第几轮
	int eventplace;//使用的场地
	float startime;//开始时间
	float endtime;//结束时间
}TrackItem;

typedef struct
{
	char name[50];
	int eventsID;
	int Size;
	item_athlete Athlete;
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
	int next_id;
	struct __AMTree* ath_map;

}Organization;

//田赛连接表
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
