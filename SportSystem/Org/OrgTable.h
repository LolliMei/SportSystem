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
}*org_list;

org_list InitOrgTable(int capacity);


void DisposeOrgTable(org_list OrgTable);


//�ж������Ƿ�Ϊ��
bool OrgTableEmpty(org_list OrgTable);


//��������
void org_resize(org_list OrgTable,int newCapacity);


void internalRangeCheck(org_list table,int index);


//����ָ��λ��
void OrgTableAddAt(org_list table, int index, Organization element);


//ĩβ���һ��Ԫ��
void OrgTableAddLast(org_list OrgTable,Organization element);


//��ͷ�����һ��Ԫ��
void OrgTableAddFirst(org_list OrgTable,Organization element);


//��ȡָ������λ�õ�Ԫ��
Organization OrgTableGet(org_list OrgTable,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Organization OrgTableSet(org_list OrgTable,int index,Organization element);


//��ѯ�Ƿ���ָ����Ԫ��
bool OrgTableContains(org_list OrgTable,Organization element);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int OrgTableFind(org_list OrgTable,Organization element);


//ɾ��ָ��λ�õĴ洢����
void OrgTableRemoveAt(org_list OrgTable, int index);


//ɾ��ָ����Ԫ��
void OrgTableRemove(org_list OrgTable,Organization element);


//ɾ��OrgTable�е�һ��Ԫ��
void OrgTableRemoveFirst(org_list OrgTable);


//ɾ��OrgTable�����һ��Ԫ��
void OrgTableRemoveLast(org_list OrgTable);


void OrgTableToString(org_list OrgTable);















#endif //INC_2019SPRINGDSA_OrgTable_H
