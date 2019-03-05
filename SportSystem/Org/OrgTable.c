//
// Created by ������ on 2019-02-23.
//
#include "../Org/OrgTable.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>
#include <string.h>

OrgTable InitOrgTable(int capacity)
{
    OrgTable table = (OrgTable)malloc(sizeof(struct __OrgTable));
	table->size = 0;
	table->capacity = capacity;
	table->data = (Organization*)malloc(sizeof(Organization)*capacity);
    return table;
}

void DisposeOrgTable(OrgTable OrgTable)
{
    free(OrgTable->data);
    OrgTable->data = NULL;
    free(OrgTable);
    OrgTable = NULL;
}

//�ж������Ƿ�Ϊ��
bool OrgTableEmpty(OrgTable OrgTable)
{
    return OrgTable->size == 0;
}

//��������
void org_resize(OrgTable OrgTable,int newCapacity)
{
    //��������
    Organization* newData =(Organization*)malloc(sizeof(Organization) * newCapacity);
    for (int i = 0; i < OrgTable->size; ++i) {
        newData[i] = OrgTable->data[i];
    }
    Organization* oldData = OrgTable->data;
    OrgTable->data = newData;
    OrgTable->capacity = newCapacity;
    free(oldData);
}

void internalRangeCheck(OrgTable table,int index)
{
    assert(!(index < 0 || index > table->size));
}

//����ָ��λ��
void OrgTableAddAt(OrgTable table, int index, Organization element)
{
    internalRangeCheck(table,index);
    if(table->size == table->capacity)
        org_resize(table,2 * table->size);

    for (int i = table->size - 1; i >= index; --i) {
        table->data[i + 1] = table->data[i];
    }
    table->data[index] = element;
    table->size ++;

}

//ĩβ���һ��Ԫ��
void OrgTableAddLast(OrgTable OrgTable,Organization element)
{
    OrgTableAddAt(OrgTable, OrgTable->size, element);
}

//��ͷ�����һ��Ԫ��
void OrgTableAddFirst(OrgTable OrgTable,Organization element)
{
    OrgTableAddAt(OrgTable, 0, element);
}

//��ȡָ������λ�õ�Ԫ��
Organization OrgTableGet(OrgTable OrgTable,int index)
{
    internalRangeCheck(OrgTable,index);
    return OrgTable->data[index];
}

//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Organization OrgTableSet(OrgTable OrgTable,int index,Organization element)
{
    internalRangeCheck(OrgTable,index);
    Organization oldVal = OrgTable->data[index];
    OrgTable->data[index] = element;
    return oldVal;
}


int OrgTableFind(OrgTable table, Organization element)
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

//ɾ��ָ��λ�õĴ洢����
void OrgTableRemoveAt(OrgTable OrgTable, int index)
{
    internalRangeCheck(OrgTable,index);
    for (int i = index + 1; i < OrgTable->size; ++i) {
        OrgTable->data[i - 1] = OrgTable->data[i];
    }
    OrgTable->size --;
}



//ɾ��ָ����Ԫ��
void OrgTableRemove(OrgTable OrgTable,Organization element)
{
    int index = OrgTableFind(OrgTable,element);
    if(index != -1)
        OrgTableRemoveAt(OrgTable,index);
}

//ɾ��OrgTable�е�һ��Ԫ��
void OrgTableRemoveFirst(OrgTable OrgTable)
{
    OrgTableRemoveAt(OrgTable,0);
}

//ɾ��OrgTable�����һ��Ԫ��
void OrgTableRemoveLast(OrgTable OrgTable)
{
    OrgTableRemoveAt(OrgTable,OrgTable->size - 1);
}

void OrgTableToString(OrgTable OrgTable)
{
    printf("[");
    printf("%d",OrgTable->data[0]);
    for (int i = 1; i < OrgTable->size; ++i) {
        printf(", %d",OrgTable->data[i]);
    }
    printf("]\n");
}