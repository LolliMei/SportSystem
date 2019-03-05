//
// Created by ������ on 2019-02-23.
//
#include "../Vector_ath/Vector.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>

Vector InitVector(int capacity)
{
    Vector vector = malloc(sizeof(struct __Vector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(ElementType)*capacity);
    return vector;
}

void DisposeVector(Vector vector)
{
    free(vector->data);
    vector->data = NULL;
    free(vector);
    vector = NULL;
}

//�ж������Ƿ�Ϊ��
bool VectorEmpty(Vector vector)
{
    return vector->size == 0;
}

//��������
void _resize(Vector vector,int newCapacity)
{
    //��������
    ElementType* newData =(ElementType*)malloc(sizeof(ElementType) * newCapacity);
    for (int i = 0; i < vector->size; ++i) {
        newData[i] = vector->data[i];
    }
    ElementType* oldData = vector->data;
    vector->data = newData;
    vector->capacity = newCapacity;
    free(oldData);
}

void _range_check(Vector vector,int index)
{
    assert(!(index < 0 || index > vector->size));
}

//����ָ��λ��
void VectorAddAt(Vector vector, int index, ElementType element)
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
void VectorAddLast(Vector vector,ElementType element)
{
    VectorAddAt(vector, vector->size, element);
}

//��ͷ�����һ��Ԫ��
void VectorAddFirst(Vector vector,ElementType element)
{
    VectorAddAt(vector, 0, element);
}

//��ȡָ������λ�õ�Ԫ��
ElementType VectorGet(Vector vector,int index)
{
    _range_check(vector,index);
    return vector->data[index];
}

//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
ElementType VectorSet(Vector vector,int index,ElementType element)
{
    _range_check(vector,index);
    ElementType oldVal = vector->data[index];
    vector->data[index] = element;
    return oldVal;
}

//��ѯ�Ƿ���ָ����Ԫ��
bool VectorContains(Vector vector,ElementType element)
{
    for (int i = 0; i < vector->size; ++i) {
        if(vector->data[i] == element) return true;
    }
    return false;
}

//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int VectorFind(Vector vector,ElementType element)
{
    for (int i = 0; i < vector->size; ++i) {
        if(vector->data[i] == element) return i;
    }
    return -1;
}

//ɾ��ָ��λ�õĴ洢����
ElementType VectorRemoveAt(Vector vector, int index)
{
    _range_check(vector,index);
    ElementType delVal = vector->data[index];
    for (int i = index + 1; i < vector->size; ++i) {
        vector->data[i - 1] = vector->data[i];
    }

    vector->size --;
    return delVal;
}

//ɾ��ָ����Ԫ��
ElementType VectorRemove(Vector vector,ElementType element)
{
    int index = VectorFind(vector,element);
    if(index != -1)
        VectorRemoveAt(vector,index);
}

//ɾ��Vector�е�һ��Ԫ��
ElementType VectorRemoveFirst(Vector vector)
{
    return VectorRemoveAt(vector,0);
}

//ɾ��Vector�����һ��Ԫ��
ElementType VectorRemoveLast(Vector vector)
{
    return VectorRemoveAt(vector,vector->size - 1);
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