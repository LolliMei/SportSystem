//
// Created by ������ on 2019-02-18.
//
#include "track_item_map.h"

ValueType1 get_trackitem(track_item_map map, KeyType1 key)
{
	//���㲢�õ���ϣ��������
	int index = trackitem_hash_index(key, map);
	TEntry* entryList = map->table[index];
	//��������Ѱ��
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
	//���Ҳ��������ؿ�
	return NULL;
}

bool contains_trackitem(track_item_map map, KeyType1 key)
{
	int index = trackitem_hash_index(key, map);

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

ValueType1 set_trackitem(track_item_map map, KeyType1 key, ValueType1 value)
{
	int index = trackitem_hash_index(key, map);

	//��������ͷ�ڵ�
	TEntry* dummyHead = (TEntry*)malloc(sizeof(TEntry));
	dummyHead->next = map->table[index];
	TEntry* node = dummyHead;
	while (node != NULL)
	{
		//���ƥ��key�����¼��ֵ
		if (node->key == key)
		{
			ValueType1 oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	free(dummyHead);

	return NULL;
}

void add_track(track_item_map map, KeyType1 key, ValueType1 value)
{
	//ͨ���󶨵�hash���������Hashֵ
	
	int index = trackitem_hash_index(key, map);

	//���Hash��λ��û�б�ռ��,����ӽ�λ����
	if (map->table[index] == NULL)
	{
		map->table[index] = create_track_entry(index, key, value);
		map->size++;
	}
	//���hashֵ�Ѿ�������
	else
	{
		TEntry* entry = map->table[index];
		TEntry* newNode = create_track_entry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

TEntry* create_track_entry(int hash, KeyType1 key, ValueType1 value)
{
	TEntry* entry = (TEntry*)malloc(sizeof(struct _TEntry));
	if (entry == NULL) exit(-1);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return entry;
}

track_item_map init_track_table(int capacity)
{
	track_item_map map = (track_item_map)malloc(sizeof(struct __THashMap));
	map->size = 0;
	map->capacity = get_capacity(capacity);
	
	//map->table = malloc(sizeof(TEntry)*capacity);
	for (int i = 0; i < map->capacity; ++i) {
		map->table[i] = NULL;
	}
	return map;
}

int trackitem_hash_index(int key, track_item_map map)
{
	return key % map->capacity;
}

int get_capacity(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

