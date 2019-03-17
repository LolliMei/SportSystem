
// ����
// �鿴�����ɼ��;����ɼ�δ���
// ������Ŀ�����Լ�ϵͳ����δ���
// ������Ŀ�������˹�������Ŀ��ͨ��SuperAdmin�����鿴

#include <stdio.h>
#include <stdlib.h>
#include "forlogin.h"
#include "Interface.h"
#include "Athlete.h"
#include <string.h>
#include "AthHashMap/athlete_table.h"
#include "TrackHashMap/track_item_map.h"
#include "RaceHashMap/race_item_map.h"
#include "Org/org_list.h"
#include "data.h"
#include "../scoreRank.h"
#include "converger.h"
#define CLEARCOMMAND "cls"

extern org_list organization;

extern race_item_map RaceItemTable;

extern track_item_map TrackItemTable;

extern athlete_table AthHashTable;

extern Setting setting;

void SuperAdministrator(void);
void Administrator(void);
void Visitor(void);
void Announcement(void);
int Apply(int flag);
int AthleteApply(int flag);
int Program(int flag);
int Information(int flag);
int OrganizationInformation(int flag);
int AthleteInformation(int flag);
int CompetitionInformation(int flag);
int CheckScore(int flag);
int TrackItemScore(int flag);
int RaceItemScore(int flag);
int CheckGoal(int flag);
int CheckOrganizationGoal(int flag);
int CheckAthleteGoal(int flag);
void scoreInput(void);
void Settings(void);

// ��������Ա����
void SuperAdministrator() {
	// 1.������Ŀ����(ȫ����Ŀ����)
	// 2.������Ϣ��ѯ
	// 3.�˶�Ա����
	// 4.�鿴�����
	// 5.�鿴������Ŀ
	// 6.�鿴�ɼ�
	// 7.�鿴�÷�
	// 8.ϵͳ����
	// 0.�˳�
	system(CLEARCOMMAND);
	int SAChoose;
	printf("\n0.�˳�  1.������Ŀ����(ȫ����Ŀ����)  2.������Ϣ��ѯ  3.�˶�Ա����  4.�鿴�����  5.�鿴������Ŀ  6.�鿴�ɼ�  7.�鿴�÷�  8.¼��ɼ�  9.ϵͳ����\n");
	printf("���������ѡ��:");
	scanf_s("%d", &SAChoose);
	setbuf(stdin, NULL);
	while (SAChoose < 0 || SAChoose>9) {
		printf("�����������������:");
		scanf_s("%d", &SAChoose);
		setbuf(stdin, NULL);
	}
	switch (SAChoose) {                         // ����ѡ��0��8Ϊ����֮�����ת����flag=1����¼���ܽ���
	case 0:
		exit(0);
		break;
	case 1:
		Announcement();
		break;
	case 2:
		Information(1);
		break;
	case 3:
		Apply(1);
		break;
	case 4:
		Program(1);
		break;
	case 5:
		CompetitionInformation(1);
		break;
	case 6:
		CheckScore(1);
		break;
	case 7:
		CheckGoal(1);
		break;
	case 8:
		scoreInput();
	case 9:
		Settings();
		break;
	default:
		break;
	}
}

// ����Ա����
void Administrator() {
	// 1.�˶�Ա����
	// 2.�鿴�����
	// 3.�鿴������Ŀ
	// 4.������Ϣ��ѯ
	// 4.�鿴�ɼ�
	// 5.�鿴�÷�
	// 0.�˳�
	system(CLEARCOMMAND);
	int AChoose;
	printf("\n0.�˳�  1.�˶�Ա����  2.�鿴�����  3.�鿴������Ŀ  4.������Ϣ��ѯ  5.�鿴�ɼ�  6.�鿴�÷�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &AChoose);
	setbuf(stdin, NULL);
	while (AChoose < 0 || AChoose>9) {
		printf("�����������������:");
		scanf_s("%d", &AChoose);
		setbuf(stdin, NULL);
	}
	switch (AChoose) {                              // ����ѡ��0��6Ϊ����֮�����ת����flag=2����¼����Ա����
	case 0:
		exit(0);
		break;
	case 1:
		Apply(2);
		break;
	case 2:
		Program(2);
		break;
	case 3:
		Information(2);
		break;
	case 4:
		CompetitionInformation(2);
		break;
	case 5:
		CheckScore(2);
		break;
	case 6:
		CheckGoal(2);
		break;
	default:
		break;
	}
}

// �οͽ���
void Visitor() {
	// 1.�鿴�ɼ�
	// 2.�鿴�÷�
	// 0.�˳�
	system(CLEARCOMMAND);
	int VChoose;
	printf("\n0.�˳�  1.�鿴�ɼ�  2.�鿴�÷�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &VChoose);
	setbuf(stdin, NULL);
	while (VChoose < 0 || VChoose>1) {
		printf("�����������������:");
		scanf_s("%d", &VChoose);
		setbuf(stdin, NULL);
	}
	switch (VChoose) {                      // ����ѡ��0��2Ϊ����֮�����ת����flag=3��¼�οͽ���
	case 0:
		exit(0);
		break;
	case 1:
		CheckScore(3);
		break;
	case 2:
		CheckGoal(3);
		break;
	default:
		break;
	}
}

// ������Ŀ����(ȫ����Ŀ����)
void Announcement() {
	// 1.ȷ�Ϸ���ȫ����Ŀ
	// 2.������Ŀ����
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.ȷ�Ϸ���ȫ����Ŀ\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		SuperAdministrator();
		break;
	case 1:
		system(CLEARCOMMAND);
		printf("�ѷ���ȫ����Ŀ\n");
		system("pause");
		Announcement();
		break;
	default:
		break;
	}
}

// �˶�Ա��������
int Apply(int flag) {
	// 1.�˶�Ա����
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�˶�Ա����\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			SuperAdministrator();
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Administrator();
		}
		break;
	case 1:
		if (flag == 1) {
			system(CLEARCOMMAND);
			AthleteApply(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			AthleteApply(2);
		}
		break;
	default:
		break;
	}
	return 0;
}

// �˶�Ա����
int AthleteApply(int flag) {                     // ����flagֵ�Ӷ�ȷ�����ؽ���
	char name[20], id[20],org[30];
	memset(name, '\0', sizeof(name));
	memset(id, '\0', sizeof(id));
	int num, Item[3]={-1,-1,-1};
	system(CLEARCOMMAND);

	printf("�������������:");
	setbuf(stdin, NULL);
	scanf_s("%s", name,20);

	printf("���������ID:");
	setbuf(stdin, NULL);
	scanf_s("%s", &id, 30);
	
	printf("����Ҫ�μӼ�����Ŀ:");
	setbuf(stdin, NULL);
	scanf_s("%d", &num);

	printf("��������μӵ���Ŀ�ı��:(-1ΪĬ��)");
	Athlete* athlete = (Athlete*)malloc(sizeof(Athlete));
	strcpy(athlete->id, id);
	strcpy(athlete->name, name);
	strcpy(athlete->organization, get_org_name_by_id(atoi(id)));
	athlete->score = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			athlete->events[i][j] = -1;
		}
	}

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &Item[i]);
		setbuf(stdin, NULL);
		athlete->events[i][0] = Item[i];
	}
	//�����˶�Ա�ܱ�
	add_athlete(AthHashTable, atoi(id), athlete);
	//������֯�˶�Ա��
	put_org_ath(organization->data->ath_map, atoi(id), athlete);
	//TODO:����˶�Ա��Ŀ�Ĵ���
	save_athlete("all.txt");
	//
	init_atl_eve(athlete->events, atoi(id));
	
	int choose;
	printf("\n0.�˳�ϵͳ  1.�������˵�  2.��������\n");
	printf("�������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>2) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		exit(0);
		break;
	case 1:
		if (flag == 1) {
			system(CLEARCOMMAND);
			SuperAdministrator();
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Administrator();
		}
		break;
	case 2:
		if (flag == 1) {
			system(CLEARCOMMAND);
			AthleteApply(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			AthleteApply(2);
		}
		break;
	default:
		break;
	}
	return 0;
}

// Transform Tiem
void time_tranfform(float time){
	int a=0,b=0;
	a=((int)(time)*100)/100;
    b=time*100-(a*100);
    printf("%d:%.2d",a,b);
}

// �鿴�����
int Program(int flag) {
	// 1.�鿴�����
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴�����\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			SuperAdministrator();
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Administrator();
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		//��ӡ�������(����)
		printf("������\n");
		for (int i = 0; i < RaceItemTable->capacity; i++)
		{
			REntry* entry = RaceItemTable->table[i];
			while (entry)
			{
				//raceitem in entrynode
				RaceItem* race = entry->value;
				printf("��Ŀ���ƣ�%s", race->name);
				printf("    ��Ŀid��%d", race->eventsID);
				if (race->Athlete->size < setting.minimumNums)
				{
					printf("    ȡ��\n");
				}
				else {
					printf("    ��Ŀ���������%d", race->Size);
					printf("    ��������%d", race->eventplace);
					printf("    ����ʱ��:");
					time_tranfform(race->startime);
					printf("-");
					time_tranfform(race->endtime);
					printf("\n");
				}
				entry = entry->next;
			}
		}

		printf("������\n");
		for (int i = 0; i < TrackItemTable->capacity; i++)
		{
			TEntry* entry = TrackItemTable->table[i];
			while (entry)
			{
				//raceitem in entrynode
				TrackItem* track = entry->value;

				printf("��Ŀ���ƣ�%s", track->name);
				printf("  ��Ŀid��%d", track->eventsID);
				if (track->Athlete->size < setting.minimumNums)
				{
					printf("    ȡ��\n");
				}
				else {
					printf("    ��Ŀ���������%d", track->Size);
					printf("    ��������%d", track->eventplace);
					printf("    ������Ա��Ϣ��id��name��");
					printf("    ����ʱ��:");
					time_tranfform(track->startime);
					printf("-");
					time_tranfform(track->endtime);
					printf("\n");
				}
				entry = entry->next;
			}
		}
		printf("\n0.�˳�ϵͳ  1.����������\n");
		printf("���������ѡ��:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
			scanf_s("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				SuperAdministrator();
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				Administrator();
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

// ������Ϣ��ѯ
int Information(int flag) {
	// 1.�鿴������֯��Ϣ
	// 2.�鿴�˶�Ա��Ϣ
	// 3.�鿴������Ŀ
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴������֯��Ϣ  2.�鿴�˶�Ա��Ϣ  3.�鿴������Ŀ\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			SuperAdministrator();
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Administrator();
		}
	case 1:
		if (flag == 1) {
			system(CLEARCOMMAND);
			OrganizationInformation(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			OrganizationInformation(2);
		}
		break;
	case 2:
		if (flag == 1) {
			system(CLEARCOMMAND);
			AthleteInformation(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			AthleteInformation(2);
		}
		break;
	case 3:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CompetitionInformation(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CompetitionInformation(2);
		}
		break;
	default:
		break;
	}
	return 0;
}

//��ӡһ����֯���������˶�Ա����Ϣ
void print_node(AthNode* node)
{
	printf("\n");
	Athlete* ath = node->value;
	printf("�˶�Ա����: %s\n", ath->name);
	printf("�˶�Աid: %s\n", ath->id);
	printf("�˶�Ա��֯: %s\n", ath->organization);
	for (int i = 0; i < 3; i++)
	{
		printf("������Ŀ��ţ�%d,�ɼ�%d\n", ath->events[i][0], ath->events[i][1]);		
	}
	printf("----------------------------------------------");
}

// �鿴������֯��Ϣ
int OrganizationInformation(int flag) {
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴������֯\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			Information(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Information(2);
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		//��ȡ��Ժ��֯���
		int index;
		printf("������Ҫ�鿴����Ժ��֯���");
		scanf_s("%d", &index);

		//��ʾ��Ժ�в����˶�Ա��Ϣ
		for_all(organization->data[index].ath_map->root, print_node);

		printf("\n0.�˳�ϵͳ  1.������Ϣ��ѯ\n");
		printf("���������ѡ��:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
			scanf_s("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				Information(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				Information(2);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

// �鿴�˶�Ա��Ϣ
int AthleteInformation(int flag) {

	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴�˶�Ա��Ϣ\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			Information(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Information(2);
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		// ͨ����ϣ�����
		//�����˶�Ա��Ϣ
		int id;
		printf("�����˶�Աid:");
		scanf_s("%d", &id);
		Athlete* ath = get_athlete(AthHashTable, id);
		if (ath == NULL)
		{
			printf("�Ҳ����˶�Ա");
			break;
		}
		//����˶�Ա��Ϣ
		printf("�˶�Ա����: %s\n", ath->name);
		printf("�˶�Աid: %s\n", ath->id);
		printf("�˶�Ա��֯: %s\n", ath->organization);
		for (int i = 0; i < 3; i++)
		{
			printf("������Ŀ��ţ�%d,�ɼ�%d\n", ath->events[i][0], ath->events[i][1]);
		}

		printf("����Ϊ�˶�Ա��Ϣ��\n");
		//end

		printf("\n0.�˳�ϵͳ  1.������Ϣ��ѯ\n");
		printf("���������ѡ��:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
			scanf_s("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				Information(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				Information(2);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

//��ӡ������������Ϣ
void view_raceitem()
{
	for (int i = 0; i < RaceItemTable->capacity; i++)
	{
		REntry* entry = RaceItemTable->table[i];
		while(entry)
		{
			//raceitem in entrynode
			RaceItem* race = entry->value;
			printf("��Ŀ���ƣ�%s", race->name);
			printf("    ��Ŀid��%d", race->eventsID);
			if(race->Athlete->size<setting.minimumNums)
			{
				printf("    ȡ��\n");
			}
			else {
				printf("    ��Ŀ���������%d", race->Size);
				printf("    ��������%d", race->eventplace);
				printf("    ������Ա��Ϣ��id��name��");
				for (int j = 0; j < race->Athlete->size; j++)
				{
					printf("(%s,%s)\n", race->Athlete->data[j]->id, race->Athlete->data[j]->name);
				}
			}
			entry = entry->next;
		}
	}
}

//��ӡ������������Ϣ
void view_trackitem()
{
	for (int i = 0; i < TrackItemTable->capacity; i++)
	{
		TEntry* entry = TrackItemTable->table[i];
		while (entry)
		{
			//raceitem in entrynode
			TrackItem* track = entry->value;
			
			printf("��Ŀ���ƣ�%s", track->name);
			printf("  ��Ŀid��%d", track->eventsID);
			if(track->Athlete->size<setting.minimumNums)
			{
				printf("    ȡ��\n");
			}
			else{
			printf("    ��Ŀ���������%d", track->Size);
			printf("    ��������%d", track->eventplace);
			printf("    ������Ա��Ϣ��id��name��");

			for (int j = 0; j < track->Athlete->size; j++)
			{
				printf("(%s,%s)\n", track->Athlete->data[j]->id, track->Athlete->data[j]->name);
			}
			}
			entry = entry->next;
		}
	}
}

// �鿴������Ŀ(�������������Ŀ����)
int CompetitionInformation(int flag) {
	// 1.�鿴ȫ��

	// 2.�鿴����
	
	// 3.�鿴����

	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������Ϣ��ѯ  1.�鿴ȫ��  2.�鿴����  3.�鿴����\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			Information(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Information(2);
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		// ��ӡ�����;���
		view_trackitem();
		view_raceitem();
		printf("\n0.�˳�ϵͳ  1.���ر�����Ŀ��ѯ\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1 > 1) {
			printf("�����������������:");
			scanf_s("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CompetitionInformation(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CompetitionInformation(2);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		system(CLEARCOMMAND);
		// ��ӡ������Ŀ
		view_trackitem();
		printf("\n");
		printf("\n0.�˳�ϵͳ  1.���ر�����Ŀ��ѯ\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CompetitionInformation(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CompetitionInformation(2);
			}
			break;
		default:
			break;
		}
		break;
	case 3:
		system(CLEARCOMMAND);
		// ��ӡ������Ŀ
		view_raceitem();
		printf("\n");
		printf("\n0.�˳�ϵͳ  1.���ر�����Ŀ��ѯ\n");
		printf("���������ѡ��:");
		int choice_3;
		scanf_s("%d", &choice_3);
		setbuf(stdin, NULL);
		while (choice_3 < 0 || choice_3>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_3);
			setbuf(stdin, NULL);
		}
		switch (choice_3) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CompetitionInformation(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CompetitionInformation(2);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

// �鿴�ɼ�
int CheckScore(int flag) {
	// 1.�鿴�����ɼ�
	// 2.�鿴�����ɼ�
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴�����ɼ�  2.�鿴�����ɼ�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			SuperAdministrator();
		}
		else if (flag == 2) {
			Administrator();
		}
		else if (flag == 3) {
			Visitor();
		}
		break;
	case 1:
		if (flag == 1) {
			system(CLEARCOMMAND);
			TrackItemScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			TrackItemScore(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			TrackItemScore(3);
		}
		break;
		break;
	case 2:
		if (flag == 1) {
			system(CLEARCOMMAND);
			RaceItemScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			RaceItemScore(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			RaceItemScore(3);
		}
		break;
	default:
		break;
	}
	return 0;
}

// After Check score
int after_checkTrackItemScore(int flag){
	printf("\n");
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
			scanf_s("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				if(flag==1){
					TrackItemScore(flag);
				}
				else if(flag==2){
					TrackItemScore(flag);
				}
				else if(flag==3){
					TrackItemScore(flag);
				}
				break;
			default:
				break;
		}
}

int after_checkRaceItemScore(int flag){
	printf("\n");
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
			scanf_s("%d", &choice);
			setbuf(stdin, NULL);
		}
			switch (choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				if(flag==1){
					RaceItemScore(flag);
				}
				else if(flag==2){
					RaceItemScore(flag);
				}
				else if(flag==3){
					RaceItemScore(flag);
				}
				break;
			default:
				break;
		}
}

// �鿴�����ɼ�
int TrackItemScore(int flag) {
	// 1.��������Ŀ�鿴�ɼ�
	// 2.��������֯�鿴�ɼ�
	// 3.���˶�Ա�鿴�ɼ�
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.��������Ŀ�鿴�ɼ�  2.��������֯�鿴�ɼ�  3.���˶�Ա�鿴�ɼ�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose > 3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckScore(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckScore(3);
		}
		break;
	case 1:
		// ���������Ŀ�ɼ�
		{
			system(CLEARCOMMAND);
			int itemID;
			printf("��������Ҫ��ѯ�ı�����Ŀ���:");
			scanf_s("%d",&itemID);
			
			after_checkTrackItemScore(flag);
		}
		break;
	case 2:
		// ���������֯�ɼ�
		{
			system(CLEARCOMMAND);
			int orgID;
			printf("��������Ҫ��ѯ�Ĳ�����֯���:");
			scanf_s("%d",&orgID);

			after_checkTrackItemScore(flag);
		}
		break;
	case 3:
		// ͨ����ϣ���������˶�Ա�ɼ�
		{
			system(CLEARCOMMAND);
			int id;
			printf("�����˶�Աid:");
			scanf_s("%d", &id);
			Athlete* ath = get_athlete(AthHashTable, id);
			if (ath == NULL)
			{
				printf("�Ҳ����˶�Ա");
				break;
			}
			//����˶�Ա��Ϣ
			printf("�˶�Ա����: %s\n", ath->name);
			printf("�˶�Աid: %s\n", ath->id);
			printf("�˶�Ա��֯: %s\n", ath->organization);
			for (int i = 0; i < 3; i++)
			{
				if(ath->events[i][0]/100 == 1){
					continue;
				}
				else{
					printf("������Ŀ��ţ�%d,�ɼ�%d\n", ath->events[i][0], ath->events[i][1]);
				}
			}
		}
		break;
		after_checkTrackItemScore(flag);
	default:
		break;
	}
	return 0;
}

// �鿴�����ɼ�
int RaceItemScore(int flag) {
	// 1.��������Ŀ�鿴�ɼ�
	// 2.��������֯�鿴�ɼ�
	// 3.���˶�Ա�鿴�ɼ�
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.��������Ŀ�鿴�ɼ�  2.��������֯�鿴�ɼ�  3.���˶�Ա�鿴�ɼ�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckScore(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckScore(3);
		}
		break;
case 1:
		// ���������Ŀ�ɼ�
		{
			system(CLEARCOMMAND);
			int itemID;
			printf("��������Ҫ��ѯ�ı�����Ŀ���:");
			scanf_s("%d",&itemID);
			
			TrackScoreRank();
			RaceScoreRank();
			print_Rank(itemID);

			after_checkRaceItemScore(flag);
		}
		break;
	case 2:
		// ���������֯�ɼ�
		{
			system(CLEARCOMMAND);
			int orgID;
			printf("��������Ҫ��ѯ�Ĳ�����֯���:");
			scanf_s("%d",&orgID);

			after_checkRaceItemScore(flag);

		}
		break;
	case 3:
		// ͨ����ϣ���������˶�Ա�ɼ�
		{
			system(CLEARCOMMAND);
			int athID;
			printf("��������Ҫ��ѯ���˶�Ա���:");
			scanf_s("%d",&athID);
			int id;
			printf("�����˶�Աid:");
			scanf_s("%d", &id);
			Athlete* ath = get_athlete(AthHashTable, id);
			if (ath == NULL)
			{
				printf("�Ҳ����˶�Ա");
				break;
			}
			//����˶�Ա��Ϣ
			printf("�˶�Ա����: %s\n", ath->name);
			printf("�˶�Աid: %s\n", ath->id);
			printf("�˶�Ա��֯: %s\n", ath->organization);
			for (int i = 0; i < 3; i++)
			{
				if(ath->events[i][0]/100 == 2){
					continue;
				}
				else{
					printf("������Ŀ��ţ�%d,�ɼ�%d\n", ath->events[i][0], ath->events[i][1]);
				}
			}
		}
		after_checkRaceItemScore(flag);
		break;
	default:
		break;
	}
	return 0;
}

// �鿴�÷�
int CheckGoal(int flag) {
	// 1.�鿴��֯�÷����
	// 2.�鿴�˶�Ա�÷�
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�鿴��֯�÷�  2.�鿴�˶�Ա�÷�\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose > 3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			SuperAdministrator();
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			Administrator();
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			Visitor();
		}
		break;
	case 1:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckOrganizationGoal(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckOrganizationGoal(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckOrganizationGoal(3);
		}
		break;
	case 2:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckAthleteGoal(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckAthleteGoal(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckAthleteGoal(3);
		}
		break;
	default:
		break;
	}
	return 0;
}

// �鿴��֯�÷�
int CheckOrganizationGoal(int flag) {
	// 1.�������
	// 2.�������
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	int **score =(int**)malloc(sizeof(int*) * 8 );
	for (int i = 0; i < 8; i++)
	{
		score[i] = (int*)malloc(sizeof(int) * 2);
	}
	printf("\n0.������һ��  1.�������  2.�������\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckGoal(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckGoal(3);
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		// �����������
		//TODO::������֯�÷�
		for (size_t i = 0; i < 8; i++)
		{
			score[i][0] = i + 1;
			score[i][1] = calc_total_score(organization->data[i + 1].ath_map->root);
		}

		organization_rank(score, 8, -1);



		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(2);
			}
			else if (flag == 3) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		system(CLEARCOMMAND);
		// �����������
		for (size_t i = 0; i < 8; i++)
		{
			score[i][0] = i + 1;
			score[i][1] = calc_total_score(organization->data[i + 1].ath_map->root);
		}

		organization_rank(score, 8, 1);

		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(2);
			}
			else if (flag == 3) {
				system(CLEARCOMMAND);
				CheckOrganizationGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

// �鿴ȫ���˶�Ա�÷�
int CheckAthleteGoal(int flag) {
	// 1.�������
	// 2.�������
	// 0.������һ��
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.������һ��  1.�������  2.�������\n");
	printf("���������ѡ��:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			system(CLEARCOMMAND);
			CheckScore(1);
		}
		else if (flag == 2) {
			system(CLEARCOMMAND);
			CheckGoal(2);
		}
		else if (flag == 3) {
			system(CLEARCOMMAND);
			CheckGoal(3);
		}
		break;
	case 1:
		system(CLEARCOMMAND);
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(2);
			}
			else if (flag == 3) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		system(CLEARCOMMAND);
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
			scanf_s("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(1);
			}
			else if (flag == 2) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(2);
			}
			else if (flag == 3) {
				system(CLEARCOMMAND);
				CheckAthleteGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

// ScoreInput
void scoreInput(){
	system(CLEARCOMMAND);
	int id;
	printf("");
	scanf_s("%d",&id);
}

// �鿴ϵͳ����
void Settings() {
	FILE* fp;
	int flag = fopen_s(&fp,"Setting.txt","r+");
	system(CLEARCOMMAND);
	printf("��ǰ���ã�\n");
	printf("��Ŀ��Сȡ������:  %d��\n", setting.minimumNums);
	for (int i = 0; i < 6; i++)
	{
		printf("��%d���÷֣�%d\n", i + 1, setting.Rankscores[i]);
	}
	system("pause");
	int choice;
	printf("��������Ҫ�޸ĵ���Ŀ\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
		case 1:
			printf("�������޸ĺ����С��������:");
			scanf_s("%d", &setting.minimumNums);
		break;
		case 2:
			printf("����������1-6���ĵ÷�Ȩ��:\n");
			for (int i = 0; i < 6; i++)
			{
				scanf_s("%d", &setting.Rankscores[i]);
			}
		break;
		default:

		break;
	}
	save_setting("Setting.txt");
	SuperAdministrator();
}
