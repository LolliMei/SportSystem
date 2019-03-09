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
int get_capacity(const int n)
{
    return (int)pow(2,ceil(log(n)/log(2)));
}

//得到对象在哈希表中的存储索引
int trackitem_hash_index(TrackItem* obj, TrackHashMap* map)
{
	return obj->eventsID;
}

//初始化哈希表
TrackHashMap init_track_table(int capacity)
{
    TrackHashMap map = (TrackHashMap)malloc(sizeof(struct __THashMap));
    map->size = 0;
    map->capacity = get_capacity(capacity);
    map->hashIndex = trackitem_hash_index;
    //map->table = malloc(sizeof(TEntry)*capacity);
    for (int i = 0; i < map->capacity; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

//创建存储节点
TEntry* create_track_entry(int hash,KeyType key,ValueType value)
{
    TEntry* entry = (TEntry*)malloc(sizeof(struct _TEntry));
    if(entry == NULL) exit(-1);
    entry->hash = hash;
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// 把一个元素放入Hash表中
void add_athlete(TrackHashMap map,KeyType key,ValueType value)
{
    //通过绑定的hash函数计算出Hash值
    int index = 0;
    index = map->hashIndex((void*)key, map);
    //如果Hash表位置没有被占用,则添加进位置中
    if(map->table[index] == NULL )
    {
        map->table[index] = create_track_entry(index,key,value);
        map->size++;
    }
    //如果hash值已经存在了
    else
    {
        TEntry* entry = map->table[index];
        TEntry* newNode = create_track_entry(index,key,value);
        newNode->next = entry;
        map->table[index] = newNode;
        map->size++;
    }
}

//根据键查找HashMap中的值
ValueType get_raceitem(TrackHashMap map,KeyType key)
{
    //计算并得到哈希链表的入口
    int index = map->hashIndex((void*)key,map);
    TEntry* entryList = map->table[index];
    //在链表中寻找
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
    //查找不到，返回空
    return NULL;
}

//查看表中是否有对应的Key
bool contains_raceitem(TrackHashMap map,KeyType key)
{
    int index = map->hashIndex((void*)key,map);
    TEntry* node = map->table[index];
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

//设置hash表中key的value，同时返回旧的value
ValueType set_raceitem_map(TrackHashMap map, KeyType key, ValueType value)
{
	int index = map->hashIndex(key, map);
	//创建虚拟头节点
	TEntry* dummyHead = (TEntry*)malloc(sizeof(TEntry));
	dummyHead->next = map->table[index];
	TEntry* node = dummyHead;
	while (node != NULL)
	{
		//如果匹配key，则记录旧值
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

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
