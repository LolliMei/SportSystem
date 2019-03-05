//
// Created by ÀèîÚêÍ on 2019-02-16.
//

#ifndef INC_2019SPRINGDSA_AthMap_H
#define INC_2019SPRINGDSA_AthMap_H

#include "../def.h"
#include "../Athlete.h"



typedef struct AthNode
{
	int balanceFactor;
	int height;
	int key;
	Athlete* value;
	struct AthNode* left;
	struct AthNode* right;
}AthNode;

typedef struct __AMTree
{
	struct AthNode* root;
	int size;
}*org_ath_map;


void AthMapPut(org_ath_map tree, int key, Athlete* value);

Athlete* AthMapGet(org_ath_map tree, int key);

bool AthMapContains(org_ath_map tree, int key);

AthNode* _remove(const org_ath_map tree, AthNode* node, int key);

org_ath_map InitAthMap();

void for_all(AthNode* node, void(*Visit)(AthNode* visitnode))
{
	Visit(node);
	for_all(node->left, Visit);
	for_all(node->right, Visit);

}





#endif //INC_2019SPRINGDSA_AthMap_H
