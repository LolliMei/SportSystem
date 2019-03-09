#include "def.h"
#include "AthHashMap/AthleteTable.h"


//直接通过id查询运动员的哈希表
struct __AHashMap* AthletePool;


//初始化
inline void Init()
{
	AthletePool = init_athlete_table(256);

}
