//
// Created by ������ on 2019-02-18.
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
}*OrgTable;

OrgTable InitOrgTable(int capacity);


void DisposeOrgTable(OrgTable OrgTable);


//�ж������Ƿ�Ϊ��
bool OrgTableEmpty(OrgTable OrgTable);


//��������
void org_resize(OrgTable OrgTable,int newCapacity);


void internalRangeCheck(OrgTable table,int index);


//����ָ��λ��
void OrgTableAddAt(OrgTable table, int index, Organization element);


//ĩβ���һ��Ԫ��
void OrgTableAddLast(OrgTable OrgTable,Organization element);


//��ͷ�����һ��Ԫ��
void OrgTableAddFirst(OrgTable OrgTable,Organization element);


//��ȡָ������λ�õ�Ԫ��
Organization OrgTableGet(OrgTable OrgTable,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Organization OrgTableSet(OrgTable OrgTable,int index,Organization element);


//��ѯ�Ƿ���ָ����Ԫ��
bool OrgTableContains(OrgTable OrgTable,Organization element);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int OrgTableFind(OrgTable OrgTable,Organization element);


//ɾ��ָ��λ�õĴ洢����
void OrgTableRemoveAt(OrgTable OrgTable, int index);


//ɾ��ָ����Ԫ��
void OrgTableRemove(OrgTable OrgTable,Organization element);


//ɾ��OrgTable�е�һ��Ԫ��
void OrgTableRemoveFirst(OrgTable OrgTable);


//ɾ��OrgTable�����һ��Ԫ��
void OrgTableRemoveLast(OrgTable OrgTable);


void OrgTableToString(OrgTable OrgTable);















#endif //INC_2019SPRINGDSA_OrgTable_H
