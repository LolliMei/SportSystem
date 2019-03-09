//
// Created by 黎钰晖 on 2019-02-18.
//
#include "TrackHashMap.h"

ValueType get_trackitem(TrackHashMap map, KeyType key)
{
	//计算并得到哈希链表的入口
	int index = map->hashIndex((void*)key, map);
	TEntry* entryList = map->table[index];
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

bool contains_trackitem(TrackHashMap map, KeyType key)
{
	int index = map->hashIndex((void*)key, map);
	TEntry* node = map->table[index];
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

ValueType set_trackitem_map(TrackHashMap map, KeyType key, ValueType value)
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

void add_track(TrackHashMap map, KeyType key, ValueType value)
{
	//通过绑定的hash函数计算出Hash值
	int index = 0;
	index = map->hashIndex((void*)key, map);
	//如果Hash表位置没有被占用,则添加进位置中
	if (map->table[index] == NULL)
	{
		map->table[index] = create_track_entry(index, key, value);
		map->size++;
	}
	//如果hash值已经存在了
	else
	{
		TEntry* entry = map->table[index];
		TEntry* newNode = create_track_entry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

TEntry* create_track_entry(int hash, KeyType key, ValueType value)
{
	TEntry* entry = (TEntry*)malloc(sizeof(struct _TEntry));
	if (entry == NULL) exit(-1);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return entry;
}

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

int trackitem_hash_index(TrackItem* obj, TrackHashMap* map)
{
	return obj->eventsID;
}

int get_capacity(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

