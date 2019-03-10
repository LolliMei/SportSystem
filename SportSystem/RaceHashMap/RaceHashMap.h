//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_RACEHASHMAP_H
#define INC_2019SPRINGDSA_RACEHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "../def.h"

#define KeyType2 int
#define ValueType2 RaceItem*

typedef struct _REntry
{
    long hash;
    KeyType2 key;
    ValueType2 value;
    struct REntry* next;
}REntry;

typedef struct __RHashMap
{
    //array of REntry
    REntry* table[1048576];
    //REntry** table;
    int size;
    int capacity;
    int (*hashIndex)(void* key,void* map);
}*RaceItemHashMap;

//��ȡָ����ֵ�����С2����
int get_rcapacity(const int n);
//�õ������ڹ�ϣ���еĴ洢����
int getHashIndex(RaceItem* obj, RaceItemHashMap map);

//��ʼ����ϣ��
RaceItemHashMap init_raceitem_map(int capacity);

//�����洢�ڵ�
REntry* create_race_entry(int hash, KeyType2 key, ValueType2 value);
// ��һ��Ԫ�ط���Hash����
void add_raceitem_map(RaceItemHashMap map, KeyType2 key, ValueType2 value);

//���ݼ�����HashMap�е�ֵ
ValueType2 get_raceitem(RaceItemHashMap map, KeyType2 key);

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_raceitem(RaceItemHashMap map, KeyType2 key);

//����hash����key��value��ͬʱ���ؾɵ�value
ValueType2 set_raceitem_map(RaceItemHashMap map, KeyType2 key, ValueType2 value);

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
