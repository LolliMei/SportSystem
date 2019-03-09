#pragma once
#include "Org/OrgTable.h"

void save_athlete(AthHashMap map, char* filename);

void load_athlete(AthHashMap map, char* filename);

void save_organization(OrgTable table, char* filename);

void load_organization(OrgTable table, char* filename);