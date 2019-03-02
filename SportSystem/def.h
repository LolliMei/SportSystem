#pragma once

#include "../SportSystem/Vector/Vector.h"

enum place
{
	track1,track2,race1,race2
};
typedef struct
{
	int id;
	char* name;
    char* organization;//departments or colleges
	int events[3];//fill in with eventsID
}Athlete;


typedef struct
{
	int eventsID;
	int Size;
	Vector Ahelte;
	int raceturn;//区别是第几轮
	enum place eventplace;//使用的场地
	float startime;//开始时间
	float endtime;//结束时间
}TrackItem;

typedef struct
{
	int eventsID;
	int Size;
	Vector Ahelte;
	int raceturn;//区别是第几轮
	enum place eventplace;//使用的场地
	float startime;//开始时间
	float endtime;//结束时间
}RaceItem;


typedef struct
{
	int minimumNums;//最小参赛人数，低于这个会被取消项目
	int Rankscores[6];//不同排名获得的分数
}Setting;



