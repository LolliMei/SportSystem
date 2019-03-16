//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "athlete_table.h"
#include <stdio.h>


//��ȡָ����ֵ�����С2����
int minTwoPow(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

//�õ������ڹ�ϣ���еĴ洢����
int index(int key, athlete_table map)
{
	return key%map->capacity;
}

//��ʼ����ϣ��
athlete_table init_athlete_table(int capacity)
{
	athlete_table map = (athlete_table)malloc(sizeof(struct __AHashMap));
	map->size = 0;
	map->capacity = minTwoPow(capacity);
	map->table = malloc(sizeof(Entry)*capacity);
	for (int i = 0; i < map->capacity; ++i) {
		map->table[i] = NULL;
	}
	return map;
}

//�����洢�ڵ�
Entry* createEntry(int hash, int key, Athlete* value)
{
	Entry* entry = (Entry*)malloc(sizeof(struct __Entry));
	if (entry == NULL) exit(-1);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return entry;
}

// ��һ��Ԫ�ط���Hash����
void add_athlete(athlete_table map, int key, Athlete* value)
{
	//ͨ���󶨵�hash���������Hashֵ
	int i = index(key, map);
	//���Hash��λ��û�б�ռ��,����ӽ�λ����
	if (map->table[i] == NULL)
	{
		map->table[i] = createEntry(i, key, value);
		map->size++;
	}
	//���hashֵ�Ѿ������ˣ�//todo::���ҵ���ĩβ����ӽ�Entry��
	else
	{
		Entry* entry = map->table[i];
		Entry* newNode = createEntry(i, key, value);
		newNode->next = entry;
		map->table[i] = newNode;
		map->size++;
	}
}

//���ݼ�����HashMap�е�ֵ
Athlete* get_athlete(athlete_table map, int key)
{
	//���㲢�õ���ϣ��������
	int i = index(key, map);
	Entry* entryList = map->table[i];
	//��������Ѱ��
	while (entryList != NULL)
	{

		if (entryList->key == key)
		{
			return entryList->value;
		}
		if (entryList->next != NULL)
			entryList = entryList->next;
		else
			return NULL;
	}
	//���Ҳ��������ؿ�
	return NULL;
}

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_athlete(athlete_table map, int key)
{
	int i = index(key, map);

	Entry* node = map->table[i];
	while (node != NULL)
	{
		if (key == node->key)
			return true;
		else
		{
			if (node->next != NULL)
				node = node->next;
			else
				return false;
		}
	}
	return false;

}

//����hash����key��value��ͬʱ���ؾɵ�value
Athlete* set_athlete(athlete_table map, int key, Athlete* value)
{
	int i = index(key, map);

	//��������ͷ�ڵ�
	Entry* dummyHead = (Entry*)malloc(sizeof(Entry));
	dummyHead->next = map->table[i];
	Entry* node = dummyHead;
	while (node != NULL)
	{
		//���ƥ��key�����¼��ֵ
		if (node->key == key)
		{
			Athlete* oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	free(dummyHead);

	return NULL;
}

//�Ƴ���ϣ���е�Ԫ��
void remove_athlete(athlete_table map, int key)
{
	int i = index(key, map);
	Entry* list = map->table[i];
	Entry* dummyHead = (Entry*)malloc(sizeof(struct __Entry));
	dummyHead->next = list;
	struct __Entry* node = dummyHead;
	Entry* prev = node;

	while (node != NULL)
	{
		if (node->next->key == key)
		{
			prev = node;
			Entry* delNode = prev->next;
			prev->next = delNode->next;
			delNode->next = NULL;
			free(delNode);

		}
		node = node->next;
	}
	map->table[i] = dummyHead->next;
	free(dummyHead);

}

