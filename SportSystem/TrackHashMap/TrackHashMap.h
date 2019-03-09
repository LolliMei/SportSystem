//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_LINKEDHASHMAP_H
#define INC_2019SPRINGDSA_LINKEDHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "../def.h"


#define KeyType int
#define ValueType TrackItem*

typedef struct Entry
{
    long hash;
    KeyType key;
    ValueType value;
    struct Entry* next;
}Entry;

typedef struct __THashMap
{
    //array of Entry
    Entry* table[1048576];
    //Entry** table;
    int size;
    int capacity;
    int (*hashIndex)(void* key,void* map);
}*TrackHashMap;

//��ȡָ����ֵ�����С2����
int minTwoPow(const int n)
{
    return (int)pow(2,ceil(log(n)/log(2)));
}

//�õ������ڹ�ϣ���еĴ洢����
int trackitem_hash_index(TrackItem* obj, TrackHashMap* map)
{
	return obj->eventsID;
}

//��ʼ����ϣ��
TrackHashMap init_athlete_table(int capacity)
{
    TrackHashMap map = (TrackHashMap)malloc(sizeof(struct __THashMap));
    map->size = 0;
    map->capacity = minTwoPow(capacity);
    map->hashIndex = trackitem_hash_index;
    //map->table = malloc(sizeof(Entry)*capacity);
    for (int i = 0; i < map->capacity; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

//�����洢�ڵ�
Entry* create_track_entry(int hash,KeyType key,ValueType value)
{
    Entry* entry = (Entry*)malloc(sizeof(struct Entry));
    if(entry == NULL) exit(-1);
    entry->hash = hash;
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// ��һ��Ԫ�ط���Hash����
void add_athlete(TrackHashMap map,KeyType key,ValueType value)
{
    //ͨ���󶨵�hash���������Hashֵ
    int index = 0;
    index = map->hashIndex((void*)key, map);
    //���Hash��λ��û�б�ռ��,����ӽ�λ����
    if(map->table[index] == NULL )
    {
        map->table[index] = create_track_entry(index,key,value);
        map->size++;
    }
    //���hashֵ�Ѿ�������
    else
    {
        Entry* entry = map->table[index];
        Entry* newNode = create_track_entry(index,key,value);
        newNode->next = entry;
        map->table[index] = newNode;
        map->size++;
    }
}

//���ݼ�����HashMap�е�ֵ
ValueType get_raceitem(TrackHashMap map,KeyType key)
{
    //���㲢�õ���ϣ��������
    int index = map->hashIndex((void*)key,map);
    Entry* entryList = map->table[index];
    //��������Ѱ��
    while(entryList != NULL)
    {

        if(entryList->key == key)
        {
            return entryList->value;
        }
        if(entryList->next != NULL)
            entryList = entryList->next;
        else
            return NULL;
    }
    //���Ҳ��������ؿ�
    return NULL;
}

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_raceitem(TrackHashMap map,KeyType key)
{
    int index = map->hashIndex((void*)key,map);
    Entry* node = map->table[index];
    while(node != NULL)
    {
        if(key == node->key)
            return true;
        else
        {
            if(node->next != NULL)
                node = node->next;
            else
                return false;
        }
    }
    return false;

}

//����hash����key��value��ͬʱ���ؾɵ�value
ValueType set_raceitem_map(TrackHashMap map, KeyType key, ValueType value)
{
	int index = map->hashIndex(key, map);
	//��������ͷ�ڵ�
	Entry* dummyHead = (Entry*)malloc(sizeof(Entry));
	dummyHead->next = map->table[index];
	Entry* node = dummyHead;
	while (node != NULL)
	{
		//���ƥ��key�����¼��ֵ
		if (node->key == key)
		{
			ValueType oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	free(dummyHead);

	return NULL;
}

//�Ƴ���ϣ���е�Ԫ��
void remove_raceitem_map(TrackHashMap map, KeyType key)
{
	int index = map->hashIndex((void*)key, map);
	Entry* list = map->table[index];
	Entry* dummyHead = (Entry*)malloc(sizeof(struct Entry));
	dummyHead->next = list;
	Entry* node = dummyHead;
	Entry* prev = node, *delNode;

	while (node != NULL)
	{
		if (node->next->key == key)
		{
			prev = node;
			delNode = prev->next;
			prev->next = delNode->next;
			delNode->next = NULL;
			free(delNode);

		}
		node = node->next;
	}
	map->table[index] = dummyHead->next;
	free(dummyHead);


}
#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
