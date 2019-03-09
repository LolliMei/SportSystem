//
// Created by 黎钰晖 on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_VECTOR_H
#define INC_2019SPRINGDSA_VECTOR_H

#include "stdbool.h"
#include "../Athlete.h"


typedef struct __Vector
{
    Athlete* data;
    int size;
    int capacity;
}*AthVector;

AthVector init_ath_vector(int capacity);


void dispose_ath_vector(AthVector vector);


//判断数组是否为空
bool empty_ath_vector(AthVector vector);


//数组扩容
void _resize(AthVector vector,int newCapacity);


void _range_check(AthVector vector,int index);


//插入指定位置
void add_at_ath_vector(AthVector vector, int index, Athlete element);


//末尾添加一个元素
void push_back_ath_vector(AthVector vector,Athlete element);


//在头部添加一个元素
void push_front_ath_vector(AthVector vector,Athlete element);


//获取指定索引位置的元素
Athlete get_ath_vector_index(AthVector vector,int index);


//设置指定索引位置的元素,返回旧值
Athlete set_ath_vector_index(AthVector vector,int index,Athlete element);


//查询是否含有指定的元素
bool VectorContains(AthVector vector,int ath_id);


//查找指定元素下标，找不到则返回-1
int find_ath_vector(AthVector vector,int ath_id);

//删除指定位置的存储对象
Athlete remove_ath_vector_atindex(AthVector vector, int index);


//删除指定的元素
Athlete remove_ath_vector(AthVector vector,int ath_id);


//删除Vector中第一个元素
Athlete remove_last_ath_vector(AthVector vector);


//删除Vector中最后一个元素
Athlete remove_first_ath_vector(AthVector vector);


void VectorToString(AthVector vector);















#endif //INC_2019SPRINGDSA_VECTOR_H
