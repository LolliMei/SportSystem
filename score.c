#include <stdio.h>
#include "scoreRank.h"
#include "../SportSystem/SportSystem/RaceHashMap/race_item_map.h"
#include "../SportSystem/SportSystem/TrackHashMap/track_item_map.h"
#include "../SportSystem/SportSystem/AthHashMap/athlete_table.h"
extern Setting setting;

extern race_item_map RaceItemTable;
extern track_item_map TrackItemTable;
extern athlete_table AthHashTable;

int athlete_getscore(){
    
    int itemid;

    RaceItem* race = get_raceitem(RaceItemTable,itemid);

    TrackItem* track = get_trackitem(TrackItemTable,itemid);



    for(int i=0;i<setting.getScoreOrder;i++){
        race->Athlete[i].data[i]->score += setting.Rankscores[i];
    }
}