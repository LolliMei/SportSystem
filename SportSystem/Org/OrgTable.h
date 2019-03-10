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
}*org_list;

org_list InitOrgTable(int capacity);


void DisposeOrgTable(org_list OrgTable);


//判断数组是否为空
bool OrgTableEmpty(org_list OrgTable);


//数组扩容
void org_resize(org_list OrgTable,int newCapacity);


void internalRangeCheck(org_list table,int index);


//插入指定位置
void OrgTableAddAt(org_list table, int index, Organization element);


//末尾添加一个元素
void OrgTableAddLast(org_list OrgTable,Organization element);


//在头部添加一个元素
void OrgTableAddFirst(org_list OrgTable,Organization element);


//获取指定索引位置的元素
Organization OrgTableGet(org_list OrgTable,int index);


//设置指定索引位置的元素,返回旧值
Organization OrgTableSet(org_list OrgTable,int index,Organization element);


//查询是否含有指定的元素
bool OrgTableContains(org_list OrgTable,Organization element);


//查找指定元素下标，找不到则返回-1
int OrgTableFind(org_list OrgTable,Organization element);


//删除指定位置的存储对象
void OrgTableRemoveAt(org_list OrgTable, int index);


//删除指定的元素
void OrgTableRemove(org_list OrgTable,Organization element);


//删除OrgTable中第一个元素
void OrgTableRemoveFirst(org_list OrgTable);


//删除OrgTable中最后一个元素
void OrgTableRemoveLast(org_list OrgTable);


void OrgTableToString(org_list OrgTable);















#endif //INC_2019SPRINGDSA_OrgTable_H
