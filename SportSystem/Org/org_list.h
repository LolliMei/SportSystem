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

org_list init_org_list(int capacity);


void dispose_org_list(org_list org_list);


//�ж������Ƿ�Ϊ��
bool is_org_list_empty(org_list org_list);


//��������
void org_resize(org_list org_list,int newCapacity);


void org_list_range_check(org_list table,int index);


//����ָ��λ��
void add_at_org_list(org_list table, int index, Organization element);


//ĩβ���һ��Ԫ��
void add_last_prg_list(org_list org_list,Organization element);


//��ͷ�����һ��Ԫ��
void add_first_org_list(org_list org_list,Organization element);


//��ȡָ������λ�õ�Ԫ��
Organization get_org_list(org_list org_list,int index);


//����ָ������λ�õ�Ԫ��,���ؾ�ֵ
Organization set_org_list(org_list org_list,int index,Organization element);


//��ѯ�Ƿ���ָ����Ԫ��
bool contains_org_list(org_list org_list,Organization element);


//����ָ��Ԫ���±꣬�Ҳ����򷵻�-1
int find_index_org_list(org_list org_list,Organization element);


//ɾ��ָ��λ�õĴ洢����
void remove_at_org_list(org_list org_list, int index);


//ɾ��ָ����Ԫ��
void remove_org_list(org_list org_list,Organization element);


//ɾ��org_list�е�һ��Ԫ��
void remove_first_org_list(org_list org_list);


//ɾ��org_list�����һ��Ԫ��
void remove_last_org_list(org_list org_list);
















#endif //INC_2019SPRINGDSA_OrgTable_H
