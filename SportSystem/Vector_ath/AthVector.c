//
// Created by ������ on 2019-02-18.
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
}*Vector;

Vector InitVector(int capacity);


void DisposeVector(Vector vector);


//�ж������Ƿ�Ϊ��
bool VectorEmpty(Vector vector);


//��������
void _resize(Vector vector,int newCapacity);


void _range_check(Vector vector,int index);


//����ָ��λ��
void VectorAddAt(Vector vector, int index, Athlete element);


//ĩβ���һ��Ԫ��
void VectorAddLast(Vector vector,Athlete element);


//��ͷ�����һ��Ԫ��
void VectorAddFirst(Vector vector,Athlete element);


//��ȡָ������λ�õ�Ԫ��
Athlete VectorGet(Vector vector,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Athlete VectorSet(Vector vector,int index,Athlete element);


//��ѯ�Ƿ���ָ����Ԫ��
bool VectorContains(Vector vector,Athlete element);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int VectorFind(Vector vector,Athlete element);

//ɾ��ָ��λ�õĴ洢����
Athlete VectorRemoveAt(Vector vector, int index);


//ɾ��ָ����Ԫ��
Athlete VectorRemove(Vector vector,Athlete element);


//ɾ��Vector�е�һ��Ԫ��
Athlete VectorRemoveFirst(Vector vector);


//ɾ��Vector�����һ��Ԫ��
Athlete VectorRemoveLast(Vector vector);


void VectorToString(Vector vector);















#endif //INC_2019SPRINGDSA_VECTOR_H
