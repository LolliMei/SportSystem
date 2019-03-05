//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "AthleteTable.h"


//��ȡָ����ֵ�����С2����
int minTwoPow(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

//�õ������ڹ�ϣ���еĴ洢����
int getHashIndex(int key, AthHashMap map)
{
	return key;
}

//��ʼ����ϣ��
AthHashMap InitHashMap(int capacity)
{
	AthHashMap map = (AthHashMap)malloc(sizeof(struct __AHashMap));
	map->size = 0;
	map->capacity = minTwoPow(capacity);
	//map->table = malloc(sizeof(Entry)*capacity);
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
void HashMapPut(AthHashMap map, int key, Athlete* value)
{
	//ͨ���󶨵�hash���������Hashֵ
	int index = 0;
	index = getHashIndex(key, map);
	//���Hash��λ��û�б�ռ��,�����ӽ�λ����
	if (map->table[index] == NULL)
	{
		map->table[index] = createEntry(index, key, value);
		map->size++;
	}
	//���hashֵ�Ѿ������ˣ�//todo::���ҵ���ĩβ�����ӽ�Entry��
	else
	{
		Entry* entry = map->table[index];
		Entry* newNode = createEntry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

//���ݼ�����HashMap�е�ֵ
Athlete* get_athlete(AthHashMap map, int key)
{
	//���㲢�õ���ϣ���������
	int index = getHashIndex(key, map);
	Entry* entryList = map->table[index];
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
bool HashMapContains(AthHashMap map, int key)
{
	int index = getHashIndex(key, map);

	Entry* node = map->table[index];
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
Athlete* set_athlete(AthHashMap map, int key, Athlete* value)
{
	int index = getHashIndex(key, map);

	//��������ͷ�ڵ�
	Entry* dummyHead = (Entry*)malloc(sizeof(Entry));
	dummyHead->next = map->table[index];
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
void HashMapRemove(AthHashMap map, int key)
{

	int index = getHashIndex(key, map);
	Entry* list = map->table[index];
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
	map->table[index] = dummyHead->next;
	free(dummyHead);


}