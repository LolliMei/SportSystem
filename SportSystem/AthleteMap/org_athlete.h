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
}*org_athlete;


void AthMapPut(org_athlete tree, int key, Athlete* value);

Athlete* get_org_ath(org_athlete tree, int key);

bool contains_org_ath(org_athlete tree, int key);

AthNode* _remove(const org_athlete tree, AthNode* node, int key);

org_athlete InitAthMap();

void for_all(AthNode* node, void (*Visit)(AthNode* visitnode));


#endif //INC_2019SPRINGDSA_AthMap_H
