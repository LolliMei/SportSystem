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
		case 5:	organization = '����'; break;
		case 6:	organization = '֪��'; break;
		case 7:	organization = '˼Դ'; break;
		case 8:	organization = '����'; break;
	}


}