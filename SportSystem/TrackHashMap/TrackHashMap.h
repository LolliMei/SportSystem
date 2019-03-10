//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_TRACKHASHMAP_H
#define INC_2019SPRINGDSA_TRACKHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "../def.h"


#define KeyType1 int
#define ValueType1 TrackItem*

typedef struct _TEntry
{
    long hash;
    KeyType1 key;
    ValueType1 value;
    struct Entry* next;
}TEntry;

typedef struct __THashMap
{
    //array of TEntry
    TEntry* table[1048576];
    //TEntry** table;
    int size;
    int capacity;
}*TrackHashMap;

//��ȡָ����ֵ�����С2����
int get_capacity(const int n);

//�õ������ڹ�ϣ���еĴ洢����
int trackitem_hash_index(int obj, TrackHashMap map);

//��ʼ����ϣ��
TrackHashMap init_track_table(int capacity);

//�����洢�ڵ�
TEntry* create_track_entry(int hash, KeyType1 key, ValueType1 value);

// ��һ��Ԫ�ط���Hash����
void add_track(TrackHashMap map, KeyType1 key, ValueType1 value);

//���ݼ�����HashMap�е�ֵ
ValueType1 get_trackitem(TrackHashMap map, KeyType1 key);

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_trackitem(TrackHashMap map, KeyType1 key);

//����hash����key��value��ͬʱ���ؾɵ�value
ValueType1 set_trackitem_map(TrackHashMap map, KeyType1 key, ValueType1 value);

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
