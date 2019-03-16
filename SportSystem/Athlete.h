

#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct __Athlete
{
	char id[20];
	char name[20];
	char organization[30];//departments or colleges
	int events[3][2];//fill in with eventsID and rank
	int score;      // Get score
}Athlete;

//����id��name��org����һ���˶�Աʵ��
Athlete* init_athlete(char* id, char* name, char* org);
//��������Ŀͬ�����˶�Ա��eventID������Ӧ���˶�Ա���ӵ�race/track�ṹ���vector��
void init_atl_eve(int * eventarray, int athID);

#endif // ATHLETE_H
