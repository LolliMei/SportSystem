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


#define KeyType1 int
#define ValueType1 TrackItem*

typedef struct _TEntry
{
    long hash;
    KeyType1 key;
    ValueType1 value;
    struct _TEntry* next;
}TEntry;

typedef struct __THashMap
{
    //array of TEntry
    TEntry* table[1048576];
    //TEntry** table;
    int size;
    int capacity;
}*track_item_map;

//获取指定数值后的最小2的幂
int get_capacity(const int n);

//得到对象在哈希表中的存储索引
int trackitem_hash_index(int obj, track_item_map map);

//初始化哈希表
track_item_map init_track_table(int capacity);

//创建存储节点
TEntry* create_track_entry(int hash, KeyType1 key, ValueType1 value);

// 把一个元素放入Hash表中
void add_track(track_item_map map, KeyType1 key, ValueType1 value);

//根据键查找HashMap中的值
ValueType1 get_trackitem(track_item_map map, KeyType1 key);

//查看表中是否有对应的Key
bool contains_trackitem(track_item_map map, KeyType1 key);

//设置hash表中key的value，同时返回旧的value
ValueType1 set_trackitem(track_item_map map, KeyType1 key, ValueType1 value);

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
