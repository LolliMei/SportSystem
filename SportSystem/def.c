#include "def.h"
#include "AthHashMap/AthleteTable.h"


//ֱ��ͨ��id��ѯ�˶�Ա�Ĺ�ϣ��
struct __AHashMap* AthletePool;


//��ʼ��
inline void Init()
{
	AthletePool = init_athlete_table(256);

}
