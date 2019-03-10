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

org_list init_org_list(int capacity);


void dispose_org_list(org_list org_list);


//判断数组是否为空
bool is_org_list_empty(org_list org_list);


//数组扩容
void org_resize(org_list org_list,int newCapacity);


void org_list_range_check(org_list table,int index);


//插入指定位置
void add_at_org_list(org_list table, int index, Organization element);


//末尾添加一个元素
void add_last_prg_list(org_list org_list,Organization element);


//在头部添加一个元素
void add_first_org_list(org_list org_list,Organization element);


//获取指定索引位置的元素
Organization get_org_list(org_list org_list,int index);


//设置指定索引位置的元素,返回旧值
Organization set_org_list(org_list org_list,int index,Organization element);


//查询是否含有指定的元素
bool contains_org_list(org_list org_list,Organization element);


//查找指定元素下标，找不到则返回-1
int find_index_org_list(org_list org_list,Organization element);


//删除指定位置的存储对象
void remove_at_org_list(org_list org_list, int index);


//删除指定的元素
void remove_org_list(org_list org_list,Organization element);


//删除org_list中第一个元素
void remove_first_org_list(org_list org_list);


//删除org_list中最后一个元素
void remove_last_org_list(org_list org_list);
















#endif //INC_2019SPRINGDSA_OrgTable_H
