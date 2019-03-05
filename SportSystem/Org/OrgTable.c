//
// Created by 黎钰晖 on 2019-02-23.
//
#include "../Org/OrgTable.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>
#include <string.h>

OrgTable InitOrgTable(int capacity)
{
    OrgTable table = (OrgTable)malloc(sizeof(struct __OrgTable));
	table->size = 0;
	table->capacity = capacity;
	table->data = (Organization*)malloc(sizeof(Organization)*capacity);
    return table;
}

void DisposeOrgTable(OrgTable OrgTable)
{
    free(OrgTable->data);
    OrgTable->data = NULL;
    free(OrgTable);
    OrgTable = NULL;
}

//判断数组是否为空
bool OrgTableEmpty(OrgTable OrgTable)
{
    return OrgTable->size == 0;
}

//数组扩容
void org_resize(OrgTable OrgTable,int newCapacity)
{
    //翻倍扩容
    Organization* newData =(Organization*)malloc(sizeof(Organization) * newCapacity);
    for (int i = 0; i < OrgTable->size; ++i) {
        newData[i] = OrgTable->data[i];
    }
    Organization* oldData = OrgTable->data;
    OrgTable->data = newData;
    OrgTable->capacity = newCapacity;
    free(oldData);
}

void internalRangeCheck(OrgTable table,int index)
{
    assert(!(index < 0 || index > table->size));
}

//插入指定位置
void OrgTableAddAt(OrgTable table, int index, Organization element)
{
    internalRangeCheck(table,index);
    if(table->size == table->capacity)
        org_resize(table,2 * table->size);

    for (int i = table->size - 1; i >= index; --i) {
        table->data[i + 1] = table->data[i];
    }
    table->data[index] = element;
    table->size ++;

}

//末尾添加一个元素
void OrgTableAddLast(OrgTable OrgTable,Organization element)
{
    OrgTableAddAt(OrgTable, OrgTable->size, element);
}

//在头部添加一个元素
void OrgTableAddFirst(OrgTable OrgTable,Organization element)
{
    OrgTableAddAt(OrgTable, 0, element);
}

//获取指定索引位置的元素
Organization OrgTableGet(OrgTable OrgTable,int index)
{
    internalRangeCheck(OrgTable,index);
    return OrgTable->data[index];
}

//设置指定索引位置的元素,返回旧值
Organization OrgTableSet(OrgTable OrgTable,int index,Organization element)
{
    internalRangeCheck(OrgTable,index);
    Organization oldVal = OrgTable->data[index];
    OrgTable->data[index] = element;
    return oldVal;
}


int OrgTableFind(OrgTable table, Organization element)
{
	for (size_t i = 0; i < table->size; i++)
	{
		if (strcmp(element.name,table->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除指定位置的存储对象
void OrgTableRemoveAt(OrgTable OrgTable, int index)
{
    internalRangeCheck(OrgTable,index);
    for (int i = index + 1; i < OrgTable->size; ++i) {
        OrgTable->data[i - 1] = OrgTable->data[i];
    }
    OrgTable->size --;
}



//删除指定的元素
void OrgTableRemove(OrgTable OrgTable,Organization element)
{
    int index = OrgTableFind(OrgTable,element);
    if(index != -1)
        OrgTableRemoveAt(OrgTable,index);
}

//删除OrgTable中第一个元素
void OrgTableRemoveFirst(OrgTable OrgTable)
{
    OrgTableRemoveAt(OrgTable,0);
}

//删除OrgTable中最后一个元素
void OrgTableRemoveLast(OrgTable OrgTable)
{
    OrgTableRemoveAt(OrgTable,OrgTable->size - 1);
}

void OrgTableToString(OrgTable OrgTable)
{
    printf("[");
    printf("%d",OrgTable->data[0]);
    for (int i = 1; i < OrgTable->size; ++i) {
        printf(", %d",OrgTable->data[i]);
    }
    printf("]\n");
}