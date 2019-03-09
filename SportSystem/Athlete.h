

#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct __Athlete
{
	char id[20];
	char name[20];
	char organization[30];//departments or colleges
	int events[3][2];//fill in with eventsID and rank
}Athlete;

//����id��name��org����һ���˶�Աʵ��
Athlete* init_athlete(char* id, char* name, char* org);

#endif // ATHLETE_H
