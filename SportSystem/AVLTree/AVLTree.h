//
// Created by ������ on 2019-02-16.
//

#ifndef INC_2019SPRINGDSA_AVLTREE_H
#define INC_2019SPRINGDSA_AVLTREE_H

#include <stdbool.h>

#define KeyType int
#define ValueType int


typedef struct AVLTreeNode
{
    int balanceFactor;
    int height;
    KeyType key;
    ValueType value;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
}AVLTreeNode;

typedef struct __AVLT
{
    struct AVLTreeNode* root;
    int size;
}*AVLTree;


void AVLTreePut(AVLTree tree,KeyType key,ValueType value);

ValueType AVLTreeGet(AVLTree tree,KeyType key);

bool AVLTreeContains(AVLTree tree,KeyType key);

AVLTreeNode* remove(const AVLTree tree, AVLTreeNode* node, KeyType key);

AVLTree InitAVLTree();


#endif //INC_2019SPRINGDSA_AVLTREE_H
