//
// Created by 黎钰晖 on 2019-02-23.
//
#include "../Vector_ath/AthVector.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>

Vector init_ath_vector(int capacity)
{
    Vector vector = malloc(sizeof(struct __Vector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(Athlete)*capacity);
    return vector;
}

void dispose_ath_vector(Vector vector)
{
    free(vector->data);
    vector->data = NULL;
    free(vector);
    vector = NULL;
}

//判断数组是否为空
bool empty_ath_vector(Vector vector)
{
    return vector->size == 0;
}

//数组扩容
void _resize(Vector vector,int newCapacity)
{
    //翻倍扩容
    Athlete* newData =(Athlete*)malloc(sizeof(Athlete) * newCapacity);
    for (int i = 0; i < vector->size; ++i) {
        newData[i] = vector->data[i];
    }
    Athlete* oldData = vector->data;
    vector->data = newData;
    vector->capacity = newCapacity;
    free(oldData);
}

void _range_check(Vector vector,int index)
{
    assert(!(index < 0 || index > vector->size));
}

//插入指定位置
void add_at_ath_vector(Vector vector, int index, Athlete element)
{
    _range_check(vector,index);
    if(vector->size == vector->capacity)
        _resize(vector,2 * vector->size);

    for (int i = vector->size - 1; i >= index; --i) {
        vector->data[i + 1] = vector->data[i];
    }
    vector->data[index] = element;
    vector->size ++;

}

//末尾添加一个元素
void push_back_ath_vector(Vector vector,Athlete element)
{
    add_at_ath_vector(vector, vector->size, element);
}

//在头部添加一个元素
void push_front_ath_vector(Vector vector,Athlete element)
{
    add_at_ath_vector(vector, 0, element);
}

//获取指定索引位置的元素
Athlete get_ath_vector_index(Vector vector,int index)
{
    _range_check(vector,index);
    return vector->data[index];
}

//设置指定索引位置的元素,返回旧值
Athlete set_ath_vector_index(Vector vector,int index,Athlete element)
{
    _range_check(vector,index);
    Athlete oldVal = vector->data[index];
    vector->data[index] = element;
    return oldVal;
}

//查询是否含有指定的元素
bool VectorContains(Vector vector,int ath_id)
{
    for (int i = 0; i < vector->size; ++i) {
        if(atoi(vector->data[i].id) == ath_id) 
			return true;
    }
    return false;
}

//查找指定元素下标，找不到则返回-1
int find_ath_vector(Vector vector,int ath_id)
{
    for (int i = 0; i < vector->size; ++i) {
		if (atoi(vector->data[i].id) == ath_id) 
			return i;        
    }
    return -1;
}

//删除指定位置的存储对象
Athlete remove_ath_vector_atindex(Vector vector, int index)
{
    _range_check(vector,index);
    Athlete delVal = vector->data[index];
    for (int i = index + 1; i < vector->size; ++i) {
        vector->data[i - 1] = vector->data[i];
    }

    vector->size --;
    return delVal;
}

//删除指定的元素
Athlete remove_ath_vector(Vector vector,int ath_id)
{
    int index = find_ath_vector(vector,ath_id);
    if(index != -1)
        return remove_ath_vector_atindex(vector,index);
}

//删除Vector中第一个元素
Athlete remove_last_ath_vector(Vector vector)
{
    return remove_ath_vector_atindex(vector,0);
}

//删除Vector中最后一个元素
Athlete remove_first_ath_vector(Vector vector)
{
    return remove_ath_vector_atindex(vector,vector->size - 1);
}

void VectorToString(Vector vector)
{
    printf("[");
    printf("%d",vector->data[0]);
    for (int i = 1; i < vector->size; ++i) {
        printf(", %d",vector->data[i]);
    }
    printf("]\n");
}