
#include "Org/OrgTable.h"
#include "RaceHashMap/RaceHashMap.h"
#include "TrackHashMap/TrackHashMap.h"
#include "AthHashMap/AthleteTable.h"

OrgTable organization;

RaceItemHashMap RaceItemTable;

TrackHashMap TrackItemTable;

AthHashMap AthHashTable;


void InitData()
{
	organization = (OrgTable)malloc(sizeof(struct __OrgTable));
	RaceItemTable = (RaceItemHashMap)malloc(sizeof(struct __RHashMap));
	TrackItemTable = (TrackHashMap)malloc(sizeof(struct __THashMap));
	AthHashTable = (AthHashMap)malloc(sizeof(struct __AHashMap));
}


void LoadData()
{
	
}



 
