//
// Created by 黎钰晖 on 2019-02-23.
//
#include "../Org/org_list.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>
#include <string.h>

org_list init_org_list(int capacity)
{
    org_list table = (org_list)malloc(sizeof(struct __OrgTable));
	table->size = 0;
	table->capacity = capacity;
	table->data = (Organization*)malloc(sizeof(Organization)*capacity);
    return table;
}

void dispose_org_list(org_list org_list)
{
    free(org_list->data);
    org_list->data = NULL;
    free(org_list);
    org_list = NULL;
}

//判断数组是否为空
bool is_org_list_empty(org_list org_list)
{
    return org_list->size == 0;
}

//数组扩容
void org_resize(org_list org_list,int newCapacity)
{
    //翻倍扩容
    Organization* newData =(Organization*)malloc(sizeof(Organization) * newCapacity);
    for (int i = 0; i < org_list->size; ++i) {
        newData[i] = org_list->data[i];
    }
    Organization* oldData = org_list->data;
    org_list->data = newData;
    org_list->capacity = newCapacity;
    free(oldData);
}

void org_list_range_check(org_list table,int index)
{
    assert(!(index < 0 || index > table->size));
}

//插入指定位置
void add_at_org_list(org_list table, int index, Organization element)
{
    org_list_range_check(table,index);
    if(table->size == table->capacity)
        org_resize(table,2 * table->size);

    for (int i = table->size - 1; i >= index; --i) {
        table->data[i + 1] = table->data[i];
    }
    table->data[index] = element;
    table->size ++;

}

//末尾添加一个元素
void add_last_prg_list(org_list org_list,Organization element)
{
    add_at_org_list(org_list, org_list->size, element);
}

//在头部添加一个元素
void add_first_org_list(org_list org_list,Organization element)
{
    add_at_org_list(org_list, 0, element);
}

//获取指定索引位置的元素
Organization get_org_list(org_list org_list,int index)
{
    org_list_range_check(org_list,index);
    return org_list->data[index];
}

//设置指定索引位置的元素,返回旧值
Organization set_org_list(org_list org_list,int index,Organization element)
{
    org_list_range_check(org_list,index);
    Organization oldVal = org_list->data[index];
    org_list->data[index] = element;
    return oldVal;
}

int find_index_org_list(org_list table, Organization element)
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
void remove_at_org_list(org_list org_list, int index)
{
    org_list_range_check(org_list,index);
    for (int i = index + 1; i < org_list->size; ++i) {
        org_list->data[i - 1] = org_list->data[i];
    }
    org_list->size --;
}

//删除指定的元素
void remove_org_list(org_list org_list,Organization element)
{
    int index = find_index_org_list(org_list,element);
    if(index != -1)
        remove_at_org_list(org_list,index);
}

//删除org_list中第一个元素
void remove_first_org_list(org_list org_list)
{
    remove_at_org_list(org_list,0);
}

//删除org_list中最后一个元素
void remove_last_org_list(org_list org_list)
{
    remove_at_org_list(org_list,org_list->size - 1);
}
