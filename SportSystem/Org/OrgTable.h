//
// Created by 黎钰晖 on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_OrgTable_H
#define INC_2019SPRINGDSA_OrgTable_H

#include "stdbool.h"
#include "../def.h"


typedef struct __OrgTable
{
    Organization* data;
    int size;
    int capacity;
}*OrgTable;

OrgTable InitOrgTable(int capacity);


void DisposeOrgTable(OrgTable OrgTable);


//判断数组是否为空
bool OrgTableEmpty(OrgTable OrgTable);


//数组扩容
void org_resize(OrgTable OrgTable,int newCapacity);


void internalRangeCheck(OrgTable table,int index);


//插入指定位置
void OrgTableAddAt(OrgTable table, int index, Organization element);


//末尾添加一个元素
void OrgTableAddLast(OrgTable OrgTable,Organization element);


//在头部添加一个元素
void OrgTableAddFirst(OrgTable OrgTable,Organization element);


//获取指定索引位置的元素
Organization OrgTableGet(OrgTable OrgTable,int index);


//设置指定索引位置的元素,返回旧值
Organization OrgTableSet(OrgTable OrgTable,int index,Organization element);


//查询是否含有指定的元素
bool OrgTableContains(OrgTable OrgTable,Organization element);


//查找指定元素下标，找不到则返回-1
int OrgTableFind(OrgTable OrgTable,Organization element);


//删除指定位置的存储对象
void OrgTableRemoveAt(OrgTable OrgTable, int index);


//删除指定的元素
void OrgTableRemove(OrgTable OrgTable,Organization element);


//删除OrgTable中第一个元素
void OrgTableRemoveFirst(OrgTable OrgTable);


//删除OrgTable中最后一个元素
void OrgTableRemoveLast(OrgTable OrgTable);


void OrgTableToString(OrgTable OrgTable);















#endif //INC_2019SPRINGDSA_OrgTable_H
