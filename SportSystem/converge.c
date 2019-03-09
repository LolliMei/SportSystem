#include <stdio.h>
#include "converger.h"
#include <stdlib.h>

void InitAthlete(){
	char id, organization, name;
	scanf("%s",&id);
	scanf("%s", &name);
	id = atoi(id);
	switch (id / 100) {
		case 1:	organization = 'AB'; break;
		case 2:	organization = 'CD'; break;
		case 3:	organization = 'EF'; break;
		case 4:	organization = 'G'; break;
		case 5:	organization = '至诚'; break;
		case 6:	organization = '知行'; break;
		case 7:	organization = '思源'; break;
		case 8:	organization = '弘毅'; break;
	}


}