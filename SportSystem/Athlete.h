

#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct __Athlete
{
	char id[20];
	char name[20];
	char organization[30];//departments or colleges
	int events[3][2];//fill in with eventsID and rank
}Athlete;

//根据id，name，org创建一个运动员实例
Athlete* init_athlete(char* id, char* name, char* org);
//将报名项目同步到运动员的eventID，将对应的运动员添加到race/track结构体的vector中
void init_atl_eve(int * eventarray, int athID);

#endif // ATHLETE_H
