//
// Created by 黎钰晖 on 2019-02-18.
//链地址法的HashMap实现(From JDK 1.8)
//非自动扩容版本
//

#ifndef INC_2019SPRINGDSA_TRACKHASHMAP_H
#define INC_2019SPRINGDSA_TRACKHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "../def.h"


#define KeyType int
#define ValueType TrackItem*

typedef struct _TEntry
{
    long hash;
    KeyType key;
    ValueType value;
    struct Entry* next;
}TEntry;

typedef struct __THashMap
{
    //array of TEntry
    TEntry* table[1048576];
    //TEntry** table;
    int size;
    int capacity;
    int (*hashIndex)(void* key,void* map);
}*TrackHashMap;

//获取指定数值后的最小2的幂
int get_capacity(const int n);

//得到对象在哈希表中的存储索引
int trackitem_hash_index(TrackItem* obj, TrackHashMap* map);

//初始化哈希表
TrackHashMap init_track_table(int capacity);

//创建存储节点
TEntry* create_track_entry(int hash, KeyType key, ValueType value);

// 把一个元素放入Hash表中
void add_track(TrackHashMap map, KeyType key, ValueType value);

//根据键查找HashMap中的值
ValueType get_trackitem(TrackHashMap map, KeyType key);

//查看表中是否有对应的Key
bool contains_trackitem(TrackHashMap map, KeyType key);

//设置hash表中key的value，同时返回旧的value
ValueType set_trackitem_map(TrackHashMap map, KeyType key, ValueType value);

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
