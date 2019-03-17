//
// Created by ������ on 2019-02-18.
//
#include "race_item_map.h"


//��ȡָ����ֵ�����С2����
int get_rcapacity(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

//�õ������ڹ�ϣ���еĴ洢����
int getHashIndex(int key, race_item_map map)
{
	return key % map->capacity;
}

//��ʼ����ϣ��
race_item_map init_raceitem_map(int capacity)
{
	race_item_map map = (race_item_map)malloc(sizeof(struct __RHashMap));
	map->size = 0;
	map->capacity = get_rcapacity(capacity);
	//map->table = malloc(sizeof(REntry)*capacity);
	for (int i = 0; i < map->capacity; ++i) {
		map->table[i] = NULL;
	}
	return map;
}

//�����洢�ڵ�
REntry* create_race_entry(int hash, KeyType2 key, ValueType2 value)
{
	REntry* entry = (REntry*)malloc(sizeof(struct _REntry));
	if (entry == NULL) exit(-1);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return entry;
}

// ��һ��Ԫ�ط���Hash����
void add_raceitem(race_item_map map, KeyType2 key, ValueType2 value)
{
	//ͨ���󶨵�hash���������Hashֵ
	int index = 0;
	index = getHashIndex(key, map);
	//���Hash��λ��û�б�ռ��,����ӽ�λ����
	if (map->table[index] == NULL)
	{
		map->table[index] = create_race_entry(index, key, value);
		map->size++;
	}
	//���hashֵ�Ѿ�������
	else
	{
		REntry* entry = map->table[index];
		REntry* newNode = create_race_entry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

//���ݼ�����HashMap�е�ֵ
ValueType2 get_raceitem(race_item_map map, KeyType2 key)
{
	//���㲢�õ���ϣ��������
	int index = getHashIndex(key, map);
	if (index < 0 || index >= map->capacity)  return NULL;
	REntry* entryList = map->table[index];
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

//�鿴�����Ƿ��ж�Ӧ��Key
bool contains_raceitem(race_item_map map, KeyType2 key)
{
	int index = getHashIndex(key, map);

	REntry* node = map->table[index];
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

//����hash����key��value��ͬʱ���ؾɵ�value
ValueType2 set_raceitem(race_item_map map, KeyType2 key, ValueType2 value)
{
	int index = getHashIndex(key, map);

	//��������ͷ�ڵ�
	REntry* dummyHead = (REntry*)malloc(sizeof(REntry));
	dummyHead->next = map->table[index];
	REntry* node = dummyHead;
	while (node != NULL)
	{
		//���ƥ��key�����¼��ֵ
		if (node->key == key)
		{
			ValueType2 oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	free(dummyHead);

	return NULL;
}