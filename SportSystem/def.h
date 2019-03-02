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
	int raceturn;//�����ǵڼ���
	enum place eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}TrackItem;

typedef struct
{
	int eventsID;
	int Size;
	Vector Ahelte;
	int raceturn;//�����ǵڼ���
	enum place eventplace;//ʹ�õĳ���
	float startime;//��ʼʱ��
	float endtime;//����ʱ��
}RaceItem;


typedef struct
{
	int minimumNums;//��С������������������ᱻȡ����Ŀ
	int Rankscores[6];//��ͬ������õķ���
}Setting;



