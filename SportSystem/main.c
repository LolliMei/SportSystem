#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "AVLTree/AVLTree.h"
#include "RBTree/RBTree.h"
#include "LinkedHashMap/LinkedHashMap.h"


int main(int argc, char** argv)
{
	AVLTree avl = InitAVLTree();
	RedBlackTree rb = InitializeTreeMap();
	LinkedHashMap hash = InitHashMap(100);
}