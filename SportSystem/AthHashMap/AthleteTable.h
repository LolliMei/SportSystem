//
// Created by 黎钰晖 on 2019-02-18.
//链地址法的HashMap实现(From JDK 1.8)
//非自动扩容版本
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
	Entry* table[1048576];
	//Entry** table;
	int size;
	int capacity;
	
};

typedef struct __AHashMap* AthHashMap;



//获取指定数值后的最小2的幂
int minTwoPow(const int n);
//得到对象在哈希表中的存储索引
int getHashIndex(int key, AthHashMap map);
//初始化哈希表
AthHashMap InitHashMap(int capacity);

//创建存储节点
Entry* createEntry(int hash, int key, Athlete* value);

// 把一个元素放入Hash表中
void HashMapPut(AthHashMap map, int key, Athlete* value);

//根据键查找HashMap中的值
Athlete* get_athlete(AthHashMap map, int key);

//查看表中是否有对应的Key
bool HashMapContains(AthHashMap map, int key);

//设置hash表中key的value，同时返回旧的value
Athlete* set_athlete(AthHashMap map, int key, Athlete* value);

//移除哈希表中的元素
void HashMapRemove(AthHashMap map, int key);
#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
