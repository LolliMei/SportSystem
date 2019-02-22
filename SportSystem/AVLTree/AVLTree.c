//
// Created by ������ on 2019-02-16->
//

#include "AVLTree.h"
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

//��������
AVLTree InitAVLTree()
{
	AVLTree tree = (AVLTree)malloc(sizeof(struct __AVLT));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

//����һ���ڵ�
AVLTreeNode* CreateNode(KeyType key, ValueType value) {

	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(struct AVLTreeNode));
	newNode->key = key;
	newNode->value = value;
	newNode->height = 1;
	newNode->balanceFactor = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//��ȡ�ڵ�߶�ֵ
int getHeight(AVLTreeNode* node)
{
	if (node == NULL) return 0;
	return node->height;
}

//��ȡ�ڵ��ƽ������
int getBalanceFactor(AVLTreeNode* node)
{
	if (node == NULL) return 0;
	return getHeight(node->left) - getHeight(node->right);
}

//RR��ת
AVLTreeNode* rightRotate(struct AVLTreeNode* y)
{
	//����ת
	struct AVLTreeNode* x = y->left;
	struct AVLTreeNode* T3 = x->right;
	x->right = y;
	y->left = T3;

	//���½ڵ�߶�ֵ
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	//x���µĸ��ڵ�
	return x;

}

//LL��ת
static inline AVLTreeNode* leftRotate(struct AVLTreeNode* y)
{
	//����ת
	AVLTreeNode* x = y->right;
	AVLTreeNode* t3 = x->left;

	x->left = y;
	y->right = t3;

	//���½ڵ�߶�ֵ
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	//x���µĸ��ڵ�
	return x;

}

//���������һ��Ԫ�ص��ڲ�����
AVLTreeNode* add(const AVLTree tree, AVLTreeNode* node, KeyType key, ValueType value)
{
	//����ڵ�Ϊ�գ���ֱ�Ӳ���
	if (node == NULL)
	{
		tree->size++;
		return CreateNode(key, value);
	}

	//Ѱ�Ҳ����
	if (key < node->key)
		node->left = add(tree, node->left, key, value);
	else if (key > node->key)
		node->right = add(tree, node->right, key, value);
	else
		node->value = value;

	//����ڵ�߶�
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

	//����ƽ������
	int balanceFactor = getBalanceFactor(node);

	//ά��ƽ��

	//case LL
	if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
		return rightRotate(node);

	//case RR
	if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
		return leftRotate(node);

	//case LR
	if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
	{
		//�Խڵ����ڵ����������ת��ΪLL��
		node->left = leftRotate(node->left);
		//��������ת����
		return rightRotate(node);
	}

	//case RL
	if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
	{
		//�Խڵ���ҽڵ��������ת
		node->right = rightRotate(node->right);
		//�Խڵ��������ת
		return leftRotate(node);
	}





	return node;


}

//���������Key-Value��
void AVLTreePut(AVLTree tree, KeyType key, ValueType value) {
	tree->root = add(tree, tree->root, key, value);
}

//�����Ƿ���ڶ�Ӧ��Key
bool AVLTreeContains(AVLTree tree, KeyType key)
{
	AVLTreeNode* node = tree->root;
	while (node != NULL)
	{
		if (node->key == key) return true;
		if (node->key < key) node = node->right;
		if (node->key > key) node = node->left;
	}
	return false;
}

//�����л�ȡ��ӦKey��ֵ
ValueType AVLTreeGet(AVLTree tree, KeyType key)
{
	AVLTreeNode* node = tree->root;
	while (node != NULL)
	{
		if (node->key == key) return node->value;
		if (node->key < key) node = node->right;
		if (node->key > key) node = node->left;
	}
	return NULL;
}

//���������ö�ӦKey��ֵ,���ؾɵ�Key��Ӧ��ֵ
ValueType AVLTreeSet(AVLTree tree, KeyType key, ValueType value)
{
	AVLTreeNode* node = tree->root;
	while (node != NULL)
	{
		if (node->key == key)
		{
			int oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		if (node->key < key) node = node->right;
		if (node->key > key) node = node->left;
	}
	return NULL;
}

//��������С�ڵ�
AVLTreeNode* minimum(AVLTreeNode* node)
{
	if (node->left == NULL) return node;
	return minimum(node->left);
}

//ʵ�����ڵ��ɾ��
AVLTreeNode* remove(const AVLTree tree, AVLTreeNode* node, KeyType key)
{
	if (node == NULL) return NULL;
	AVLTreeNode* retNode;
	if (key < node->key)
	{
		node->left = remove(tree, node->left, key);
		retNode = node;
	}
	else if (key > node->key)
	{
		node->right = remove(tree, node->right, key);
		retNode = node;
	}
	else
	{
		//����һ�߽ڵ�Ϊ��
		if (node->left == NULL)
		{
			AVLTreeNode* right = node->right;
			node->right = NULL;
			tree->size--;
			retNode = right;
		}

		else if (node->right == NULL)
		{
			AVLTreeNode* left = node->left;
			node->left = NULL;
			tree->size--;
			retNode = left;
		}
		//������������Ϊ��
		else
		{
			AVLTreeNode* succ = minimum(node->right);
			succ->right = remove(tree, node->right, succ->key);
			succ->left = node->left;

			node->left = node->right = NULL;

			retNode = succ;

		}
	}

	if (retNode == NULL)
		return NULL;

	// ����height
	retNode->height = 1 + max(getHeight(retNode->left), getHeight(retNode->right));

	// ����ƽ������
	int balanceFactor = getBalanceFactor(retNode);

	// ƽ��ά��
	// LL
	if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)
		return rightRotate(retNode);

	// RR
	if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0)
		return leftRotate(retNode);

	// LR
	if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
		retNode->left = leftRotate(retNode->left);
		return rightRotate(retNode);
	}

	// RL
	if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
		retNode->right = rightRotate(retNode->right);
		return leftRotate(retNode);
	}

	return retNode;




}

//���ҵ���Ӧ�Ľڵ�
AVLTreeNode* getNode(AVLTreeNode* node, KeyType key)
{

	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return getNode(node->left, key);
	else // if(key->compareTo(node->key) > 0)
		return getNode(node->right, key);
}

//ɾ�����еĽڵ�,������Key�ľ�ֵValue
ValueType AVLTreeRemove(AVLTree tree, KeyType key)
{
	AVLTreeNode* node = getNode(tree->root, key);
	if (node != NULL)
	{
		tree->root = remove(tree, tree->root, key);
		return node->value;
	}
	return NULL;
}




