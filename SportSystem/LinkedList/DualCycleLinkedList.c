//
// Created by ������ on 2019-02-15.
//

#include "DualCycleLinkedList.h"
#include <stdlib.h>
#include <stdbool.h>

//����һ��˫������ڵ�
struct DualCycNode* internalCreateNode(ElementType element)
{
    struct DualCycNode* newNode = (struct DualCycNode*)malloc(sizeof(struct DualCycNode));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = element;
    return newNode;
}

//��ʼ��ѭ��˫����,����ʽͷ�ڵ�
DualCycLinkedList InitDualCycList()
{
    DualCycLinkedList list = malloc(sizeof(struct __DCLinkedList));
    list->length = 0;
    list->head = internalCreateNode(NULL);
    list->head->next = list->head;
    list->head->prev = list->head;
    return list;
}

//�������
void DisposeDualCycList(DualCycLinkedList list)
{
    struct DualCycNode* current = list->head->next;
    //���û�з��ص�ͷ�ڵ㣬������û�н���
    while(current != list->head)
    {
        //������һ���ڵ������
        struct DualCycNode* tmp = current->next;
        //�ͷŵ�ǰ�ڵ�
        free(current);
        //�ƶ�����һ���ڵ�
        current = tmp;
    }

}

//�ж��Ƿ�Ϊ��
bool DualCycListIsEmpty(DualCycLinkedList list)
{
    return list->length == 0;
}

//����ָ���±��Ԫ��
ElementType DualCycListGetElement(DualCycLinkedList list, int index)
{

}

//�����Ƿ����
bool DualCycListContains(DualCycLinkedList list, ElementType element)
{
    struct DualCycNode* current = list->head->next;

    while(current != list->head)
    {
        if(current->data = element)
        {
            return true;
        }
        current = current->next;
    }

    return false;

}

//����һ��Ԫ�أ�ͷ�巨
void DualCycListInsert(DualCycLinkedList list, ElementType element)
{
    struct DualCycNode* newNode = internalCreateNode(element);
    struct DualCycNode* nextNode = list->head->next;

    list->head->next = newNode;
    newNode->next = nextNode;

    nextNode->prev = newNode;
    newNode->prev = list->head;

    list->length ++;


}

//ɾ��һ��Ԫ��
void DualCycListRemove(DualCycLinkedList list,ElementType element)
{
    struct DualCycNode* delNode = list->head->next;
    //��λ��ɾ���ڵ�
    while(delNode != list->head)
    {
        if(delNode->data == element) break;
        delNode = delNode->next;
    }

    //ִ��ɾ������
    struct DualCycNode* prev = delNode->prev;
    struct DualCycNode* next = delNode->next;

    prev->next = next;
    next->prev = prev;

    free(delNode);

    list->length --;

}