//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_LINKEDHASHMAP_H
#define INC_2019SPRINGDSA_LINKEDHASHMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define KeyType int
#define ValueType int

typedef struct Entry
{
    long hash;
    KeyType key;
    ValueType value;
    struct Entry* next;
}Entry;

typedef struct __HashMap
{
    //array of Entry
    Entry* table[1048576];
    //Entry** table;
    int size;
    int capacity;
    int (*hashIndex)(void* key,void* map);
}*LinkedHashMap;

//��ȡָ����ֵ�����С2����
int minTwoPow(const int n)
{
    return (int)pow(2,ceil(log(n)/log(2)));
}

//�õ������ڹ�ϣ���еĴ洢����
int getHashIndex(void* obj, void* map)
{
    LinkedHashMap hashMap = (LinkedHashMap)map;
    return abs((int)(obj)&(hashMap->capacity - 1));
}

//��ʼ����ϣ��
LinkedHashMap InitHashMap(int capacity)
{
    LinkedHashMap map = (LinkedHashMap)malloc(sizeof(struct __HashMap));
    map->size = 0;
    map->capacity = minTwoPow(capacity);
    map->hashIndex = getHashIndex;
    //map->table = malloc(sizeof(Entry)*capacity);
    for (int i = 0; i < map->capacity; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

//�����洢�ڵ�
Entry* createEntry(int hash,KeyType key,ValueType value)
{
    Entry* entry = (Entry*)malloc(sizeof(struct Entry));
    if(entry == NULL) exit(-1);
    entry->hash = hash;
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// ��һ��Ԫ�ط���Hash����
void HashMapPut(LinkedHashMap map,KeyType key,ValueType value)
{
    //ͨ���󶨵�hash���������Hashֵ
    int index = 0;
    index = map->hashIndex((void*)key, map);
    //���Hash��λ��û�б�ռ��,����ӽ�λ����
    if(map->table[index] == NULL )
    {
        map->table[index] = createEntry(index,key,value);
        map->size++;
    }
    //���hashֵ�Ѿ������ˣ�//todo::���ҵ���ĩβ����ӽ�Entry��
    else
    {
        Entry* entry = map->table[index];
        Entry* newNode = createEntry(index,key,value);
        newNode->next = entry;
        map->table[index] = newNode;
        map->size++;
    }
}

//���ݼ�����HashMap�е�ֵ
ValueType HashMapGet(LinkedHashMap map,KeyType key)
{
    //���㲢�õ���ϣ��������
    int index = map->hashIndex((void*)key,map);
    Entry* entryList = map->table[index];
    //��������Ѱ��
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
    //���Ҳ��������ؿ�
    return NULL;
}

//�鿴�����Ƿ��ж�Ӧ��Key
bool HashMapContains(LinkedHashMap map,KeyType key)
{
    int index = map->hashIndex((void*)key,map);
    Entry* node = map->table[index];
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

//����hash����key��value��ͬʱ���ؾɵ�value
ValueType HashMapSet(LinkedHashMap map,KeyType key,ValueType value)
{
	int index = map->hashIndex((void*)key, map);
	//��������ͷ�ڵ�
	Entry* node = (Entry*)malloc(sizeof(Entry));
	node->next = map->table[index];
	while (node->next != NULL)
	{
		//���ƥ��key�����¼��ֵ
		if (node->key == key)
		{
			ValueType oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	
	return NULL;
}

#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H
