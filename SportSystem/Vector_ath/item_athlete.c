//
// Created by ������ on 2019-02-23.
//
#include "../Vector_ath/item_athlete.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>

item_athlete init_ath_vector(int capacity)
{
    item_athlete vector = malloc(sizeof(struct __Vector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(Athlete*)*capacity);
    return vector;
}

void dispose_ath_vector(item_athlete vector)
{
    free(vector->data);
    vector->data = NULL;
    free(vector);
    vector = NULL;
}

//�ж������Ƿ�Ϊ��
bool empty_ath_vector(item_athlete vector)
{
    return vector->size == 0;
}

//��������
void _resize(item_athlete vector,int newCapacity)
{
    //��������
    Athlete** newData =(Athlete**)malloc(sizeof(Athlete*) * newCapacity);
    for (int i = 0; i < vector->size; ++i) {
        newData[i] = vector->data[i];
    }
    Athlete** oldData = vector->data;
    vector->data = newData;
    vector->capacity = newCapacity;
    free(oldData);
}

void _range_check(item_athlete vector,int index)
{
	//printf("%d\n", index);
    if((index < 0 || index > vector->size))
    {
		printf("fuck:%d\n", index);
		//printf("fuck!!");
    }
}

//����ָ��λ��
void add_at_ath_vector(item_athlete vector, int index, Athlete* element)
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

//ĩβ���һ��Ԫ��
void push_back_ath_vector(item_athlete vector,Athlete* element)
{
    add_at_ath_vector(vector, vector->size, element);
}

//��ͷ�����һ��Ԫ��
void push_front_ath_vector(item_athlete vector,Athlete* element)
{
    add_at_ath_vector(vector, 0, element);
}

//��ȡָ������λ�õ�Ԫ��
Athlete* get_ath_vector_index(item_athlete vector,int index)
{
    _range_check(vector,index);
    return vector->data[index];
}

//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Athlete* set_ath_vector_index(item_athlete vector,int index,Athlete* element)
{
    _range_check(vector,index);
    Athlete* oldVal = vector->data[index];
    vector->data[index] = element;
    return oldVal;
}

//��ѯ�Ƿ���ָ����Ԫ��
bool VectorContains(item_athlete vector,int ath_id)
{
    for (int i = 0; i < vector->size; ++i) {
        if(atoi(vector->data[i]->id) == ath_id) 
			return true;
    }
    return false;
}

//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int find_ath_vector(item_athlete vector,int ath_id)
{
    for (int i = 0; i < vector->size; ++i) {
		if (atoi(vector->data[i]->id) == ath_id) 
			return i;        
    }
    return -1;
}

//ɾ��ָ��λ�õĴ洢����
Athlete* remove_ath_vector_atindex(item_athlete vector, int index)
{
    _range_check(vector,index);
    Athlete* delVal = vector->data[index];
    for (int i = index + 1; i < vector->size; ++i) {
        vector->data[i - 1] = vector->data[i];
    }

    vector->size --;
    return delVal;
}

//ɾ��ָ����Ԫ��
Athlete* remove_ath_vector(item_athlete vector,int ath_id)
{
    int index = find_ath_vector(vector,ath_id);
    if(index != -1)
        return remove_ath_vector_atindex(vector,index);
}

//ɾ��Vector�е�һ��Ԫ��
Athlete* remove_last_ath_vector(item_athlete vector)
{
    return remove_ath_vector_atindex(vector,0);
}

//ɾ��Vector�����һ��Ԫ��
Athlete* remove_first_ath_vector(item_athlete vector)
{
    return remove_ath_vector_atindex(vector,vector->size - 1);
}

