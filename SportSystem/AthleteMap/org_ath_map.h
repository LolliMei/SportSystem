//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-16.
//

#ifndef INC_2019SPRINGDSA_AthMap_H
#define INC_2019SPRINGDSA_AthMap_H

#include "../def.h"
#include "../Athlete.h"
#include <stdbool.h>


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

Athlete* get_org_ath(org_ath_map tree, int key);

bool contains_org_ath(org_ath_map tree, int key);

AthNode* _remove(const org_ath_map tree, AthNode* node, int key);

org_ath_map InitAthMap();

void for_all(AthNode* node, void (*Visit)(AthNode* visitnode));


#endif //INC_2019SPRINGDSA_AthMap_H
