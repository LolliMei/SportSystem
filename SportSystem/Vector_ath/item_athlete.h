//
// Created by ������ on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_VECTOR_H
#define INC_2019SPRINGDSA_VECTOR_H

#include "stdbool.h"
#include "../Athlete.h"


typedef struct __Vector
{
    Athlete** data;
    int size;
    int capacity;
}*item_athlete;

item_athlete init_ath_vector(int capacity);


void dispose_ath_vector(item_athlete vector);


//�ж������Ƿ�Ϊ��
bool empty_ath_vector(item_athlete vector);


//��������
void _resize(item_athlete vector,int newCapacity);


void _range_check(item_athlete vector,int index);


//����ָ��λ��
void add_at_ath_vector(item_athlete vector, int index, Athlete* element);


//ĩβ���һ��Ԫ��
void push_back_ath_vector(item_athlete vector,Athlete* element);


//��ͷ�����һ��Ԫ��
void push_front_ath_vector(item_athlete vector,Athlete* element);


//��ȡָ������λ�õ�Ԫ��
Athlete* get_ath_vector_index(item_athlete vector,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Athlete* set_ath_vector_index(item_athlete vector,int index,Athlete* element);


//��ѯ�Ƿ���ָ����Ԫ��
bool VectorContains(item_athlete vector,int ath_id);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int find_ath_vector(item_athlete vector,int ath_id);

//ɾ��ָ��λ�õĴ洢����
Athlete* remove_ath_vector_atindex(item_athlete vector, int index);


//ɾ��ָ����Ԫ��
Athlete* remove_ath_vector(item_athlete vector,int ath_id);


//ɾ��Vector�е�һ��Ԫ��
Athlete* remove_last_ath_vector(item_athlete vector);


//ɾ��Vector�����һ��Ԫ��
Athlete* remove_first_ath_vector(item_athlete vector);
















#endif //INC_2019SPRINGDSA_VECTOR_H
