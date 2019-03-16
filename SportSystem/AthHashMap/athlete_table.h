//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_LINKEDHASHMAP_H
#define INC_2019SPRINGDSA_LINKEDHASHMAP_H
#include "../Athlete.h"
#include <stdbool.h>


typedef struct __Entry
{
	long hash;
	int key;
	Athlete* value;
	struct __Entry* next;
}Entry;

struct __AHashMap
{
	//array of Entry
	Entry** table;
	//Entry** table;
	int size;
	int capacity;
	
};

typedef struct __AHashMap* athlete_table;

//��ȡָ����ֵ�����С2����
int minTwoPow(const int n);

//��ʼ����ϣ��
athlete_table init_athlete_table(int capacity);

//�����洢�ڵ�
Entry* createEntry(int hash, int key, Athlete* value);

// ��һ��Ԫ�ط���Hash����
void add_athlete(athlete_table map, int key, Athlete* value);

//���ݼ�����HashMap�е�ֵ
Athlete* get_athlete(athlete_table map, int key);

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_athlete(athlete_table map, int key);

//����hash����key��value��ͬʱ���ؾɵ�value
Athlete* set_athlete(athlete_table map, int key, Athlete* value);

//�Ƴ���ϣ���е�Ԫ��
void remove_athlete(athlete_table map, int key);

//����������ϣ��
void forall_athlete(athlete_table map, void (*func)(Athlete ath));

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
