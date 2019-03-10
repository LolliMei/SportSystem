//
// Created by 黎钰晖 on 2019-02-18.
//链地址法的HashMap实现(From JDK 1.8)
//非自动扩容版本
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

//获取指定数值后的最小2的幂
int get_rcapacity(const int n);
//得到对象在哈希表中的存储索引
int getHashIndex(RaceItem* obj, RaceItemHashMap map);

//初始化哈希表
RaceItemHashMap init_raceitem_map(int capacity);

//创建存储节点
REntry* create_race_entry(int hash, KeyType2 key, ValueType2 value);
// 把一个元素放入Hash表中
void add_raceitem_map(RaceItemHashMap map, KeyType2 key, ValueType2 value);

//根据键查找HashMap中的值
ValueType2 get_raceitem(RaceItemHashMap map, KeyType2 key);

//查看表中是否有对应的Key
bool contains_raceitem(RaceItemHashMap map, KeyType2 key);

//设置hash表中key的value，同时返回旧的value
ValueType2 set_raceitem_map(RaceItemHashMap map, KeyType2 key, ValueType2 value);

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
