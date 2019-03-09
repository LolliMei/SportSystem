//
// Created by 黎钰晖 on 2019-02-18.
//链地址法的HashMap实现(From JDK 1.8)
//非自动扩容版本
//

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "AthleteTable.h"


//获取指定数值后的最小2的幂
int minTwoPow(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

//得到对象在哈希表中的存储索引
int getHashIndex(int key, AthHashMap map)
{
	return key;
}

//初始化哈希表
AthHashMap init_athlete_table(int capacity)
{
	AthHashMap map = (AthHashMap)malloc(sizeof(struct __AHashMap));
	map->size = 0;
	map->capacity = minTwoPow(capacity);
	map->table = malloc(sizeof(Entry)*capacity);
	for (int i = 0; i < map->capacity; ++i) {
		map->table[i] = NULL;
	}
	return map;
}

//创建存储节点
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

// 把一个元素放入Hash表中
void add_athlete(AthHashMap map, int key, Athlete* value)
{
	//通过绑定的hash函数计算出Hash值
	int index = 0;
	index = getHashIndex(key, map);
	//如果Hash表位置没有被占用,则添加进位置中
	if (map->table[index] == NULL)
	{
		map->table[index] = createEntry(index, key, value);
		map->size++;
	}
	//如果hash值已经存在了，//todo::则找到最末尾，添加进Entry中
	else
	{
		Entry* entry = map->table[index];
		Entry* newNode = createEntry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

//根据键查找HashMap中的值
Athlete* get_athlete(AthHashMap map, int key)
{
	//计算并得到哈希链表的入口
	int index = getHashIndex(key, map);
	Entry* entryList = map->table[index];
	//在链表中寻找
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
	//查找不到，返回空
	return NULL;
}

//查看表中是否有对应的Key
bool contains_raceitem(AthHashMap map, int key)
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

//设置hash表中key的value，同时返回旧的value
Athlete* set_athlete(AthHashMap map, int key, Athlete* value)
{
	int index = getHashIndex(key, map);

	//创建虚拟头节点
	Entry* dummyHead = (Entry*)malloc(sizeof(Entry));
	dummyHead->next = map->table[index];
	Entry* node = dummyHead;
	while (node != NULL)
	{
		//如果匹配key，则记录旧值
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

//移除哈希表中的元素
void remove_athlete(AthHashMap map, int key)
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
