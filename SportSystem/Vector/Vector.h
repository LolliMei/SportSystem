//
// Created by ������ on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_VECTOR_H
#define INC_2019SPRINGDSA_VECTOR_H

#include "stdbool.h"

#define ElementType int

typedef struct __Vector
{
    ElementType* data;
    int size;
    int capacity;
}*Vector;

Vector InitVector(int capacity);


void DisposeVector(Vector vector);


//�ж������Ƿ�Ϊ��
bool VectorEmpty(Vector vector);


//��������
void internalResize(Vector vector,int newCapacity);


void internalRangeCheck(Vector vector,int index);


//����ָ��λ��
void VectorAddAt(Vector vector, int index, ElementType element);


//ĩβ���һ��Ԫ��
void VectorAddLast(Vector vector,ElementType element);


//��ͷ�����һ��Ԫ��
void VectorAddFirst(Vector vector,ElementType element);


//��ȡָ������λ�õ�Ԫ��
ElementType VectorGet(Vector vector,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
ElementType VectorSet(Vector vector,int index,ElementType element);


//��ѯ�Ƿ���ָ����Ԫ��
bool VectorContains(Vector vector,ElementType element);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int VectorFind(Vector vector,ElementType element);

//ɾ��ָ��λ�õĴ洢����
ElementType VectorRemoveAt(Vector vector, int index);


//ɾ��ָ����Ԫ��
ElementType VectorRemove(Vector vector,ElementType element);


//ɾ��Vector�е�һ��Ԫ��
ElementType VectorRemoveFirst(Vector vector);


//ɾ��Vector�����һ��Ԫ��
ElementType VectorRemoveLast(Vector vector);


void VectorToString(Vector vector);















#endif //INC_2019SPRINGDSA_VECTOR_H
