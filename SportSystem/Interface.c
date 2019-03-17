
// 界面
// 查看田赛成绩和竞赛成绩未完成
// 比赛项目设置以及系统设置未完成
// 比赛项目设置由人工输入项目，通过SuperAdmin发布查看

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

// 超级管理员界面
void SuperAdministrator() {
	// 1.参赛项目发布(全部项目发布)
	// 2.参赛信息查询
	// 3.运动员报名
	// 4.查看秩序册
	// 5.查看比赛项目
	// 6.查看成绩
	// 7.查看得分
	// 8.系统设置
	// 0.退出
	system(CLEARCOMMAND);
	int SAChoose;
	printf("\n0.退出  1.参赛项目发布(全部项目发布)  2.参赛信息查询  3.运动员报名  4.查看秩序册  5.查看比赛项目  6.查看成绩  7.查看得分  8.录入成绩  9.系统设置\n");
	printf("请输入你的选择:");
	scanf_s("%d", &SAChoose);
	setbuf(stdin, NULL);
	while (SAChoose < 0 || SAChoose>9) {
		printf("输入错误，请重新输入:");
		scanf_s("%d", &SAChoose);
		setbuf(stdin, NULL);
	}
	switch (SAChoose) {                         // 功能选择，0～8为界面之间的跳转，用flag=1来记录超管界面
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

// 管理员界面
void Administrator() {
	// 1.运动员报名
	// 2.查看秩序册
	// 3.查看比赛项目
	// 4.参赛信息查询
	// 4.查看成绩
	// 5.查看得分
	// 0.退出
	system(CLEARCOMMAND);
	int AChoose;
	printf("\n0.退出  1.运动员报名  2.查看秩序册  3.查看比赛项目  4.参赛信息查询  5.查看成绩  6.查看得分\n");
	printf("请输入你的选择:");
	scanf_s("%d", &AChoose);
	setbuf(stdin, NULL);
	while (AChoose < 0 || AChoose>9) {
		printf("输入错误，请重新输入:");
		scanf_s("%d", &AChoose);
		setbuf(stdin, NULL);
	}
	switch (AChoose) {                              // 功能选择，0～6为界面之间的跳转，用flag=2来记录管理员界面
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

// 游客界面
void Visitor() {
	// 1.查看成绩
	// 2.查看得分
	// 0.退出
	system(CLEARCOMMAND);
	int VChoose;
	printf("\n0.退出  1.查看成绩  2.查看得分\n");
	printf("请输入你的选择:");
	scanf_s("%d", &VChoose);
	setbuf(stdin, NULL);
	while (VChoose < 0 || VChoose>1) {
		printf("输入错误，请重新输入:");
		scanf_s("%d", &VChoose);
		setbuf(stdin, NULL);
	}
	switch (VChoose) {                      // 功能选择，0～2为界面之间的跳转，用flag=3记录游客界面
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

// 参赛项目发布(全部项目发布)
void Announcement() {
	// 1.确认发布全部项目
	// 2.比赛项目设置
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.确认发布全部项目\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf_s("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		SuperAdministrator();
		break;
	case 1:
		system(CLEARCOMMAND);
		printf("已发布全部项目\n");
		system("pause");
		Announcement();
		break;
	default:
		break;
	}
}

// 运动员报名界面
int Apply(int flag) {
	// 1.运动员报名
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.运动员报名\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
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

// 运动员报名
int AthleteApply(int flag) {                     // 传入flag值从而确认跳回界面
	char name[20], id[20],org[30];
	memset(name, '\0', sizeof(name));
	memset(id, '\0', sizeof(id));
	int num, Item[3]={-1,-1,-1};
	system(CLEARCOMMAND);

	printf("请输入你的名字:");
	setbuf(stdin, NULL);
	scanf_s("%s", name,20);

	printf("请输入你的ID:");
	setbuf(stdin, NULL);
	scanf_s("%s", &id, 30);
	
	printf("你需要参加几个项目:");
	setbuf(stdin, NULL);
	scanf_s("%d", &num);

	printf("请输入你参加的项目的编号:(-1为默认)");
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
	//加入运动员总表
	add_athlete(AthHashTable, atoi(id), athlete);
	//加入组织运动员表
	put_org_ath(organization->data->ath_map, atoi(id), athlete);
	//TODO:添加运动员项目的处理
	save_athlete("all.txt");
	//
	init_atl_eve(athlete->events, atoi(id));
	
	int choose;
	printf("\n0.退出系统  1.返回主菜单  2.继续报名\n");
	printf("输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>2) {
		printf("输入错误，请重新输入:");
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

// 查看秩序册
int Program(int flag) {
	// 1.查看秩序册
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看测序册\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
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
		//打印出秩序册(函数)
		printf("竞赛：\n");
		for (int i = 0; i < RaceItemTable->capacity; i++)
		{
			REntry* entry = RaceItemTable->table[i];
			while (entry)
			{
				//raceitem in entrynode
				RaceItem* race = entry->value;
				printf("项目名称：%s", race->name);
				printf("    项目id：%d", race->eventsID);
				if (race->Athlete->size < setting.minimumNums)
				{
					printf("    取消\n");
				}
				else {
					printf("    项目最大人数：%d", race->Size);
					printf("    比赛场地%d", race->eventplace);
					printf("    比赛时间:");
					time_tranfform(race->startime);
					printf("-");
					time_tranfform(race->endtime);
					printf("\n");
				}
				entry = entry->next;
			}
		}

		printf("田赛：\n");
		for (int i = 0; i < TrackItemTable->capacity; i++)
		{
			TEntry* entry = TrackItemTable->table[i];
			while (entry)
			{
				//raceitem in entrynode
				TrackItem* track = entry->value;

				printf("项目名称：%s", track->name);
				printf("  项目id：%d", track->eventsID);
				if (track->Athlete->size < setting.minimumNums)
				{
					printf("    取消\n");
				}
				else {
					printf("    项目最大人数：%d", track->Size);
					printf("    比赛场地%d", track->eventplace);
					printf("    参赛人员信息（id，name）");
					printf("    比赛时间:");
					time_tranfform(track->startime);
					printf("-");
					time_tranfform(track->endtime);
					printf("\n");
				}
				entry = entry->next;
			}
		}
		printf("\n0.退出系统  1.返回主界面\n");
		printf("请输入你的选择:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
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

// 参赛信息查询
int Information(int flag) {
	// 1.查看参赛组织信息
	// 2.查看运动员信息
	// 3.查看比赛项目
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看参赛组织信息  2.查看运动员信息  3.查看比赛项目\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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

//打印一个组织当中所有运动员的信息
void print_node(AthNode* node)
{
	printf("\n");
	Athlete* ath = node->value;
	printf("运动员姓名: %s\n", ath->name);
	printf("运动员id: %s\n", ath->id);
	printf("运动员组织: %s\n", ath->organization);
	for (int i = 0; i < 3; i++)
	{
		printf("参赛项目编号：%d,成绩%d\n", ath->events[i][0], ath->events[i][1]);		
	}
	printf("----------------------------------------------");
}

// 查看参赛组织信息
int OrganizationInformation(int flag) {
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看参赛组织\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
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
		//获取书院组织编号
		int index;
		printf("输入需要查看的书院组织编号");
		scanf_s("%d", &index);

		//显示书院中参赛运动员信息
		for_all(organization->data[index].ath_map->root, print_node);

		printf("\n0.退出系统  1.返回信息查询\n");
		printf("请输入你的选择:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
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

// 查看运动员信息
int AthleteInformation(int flag) {

	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看运动员信息\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
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
		// 通过哈希表查找
		//输入运动员信息
		int id;
		printf("输入运动员id:");
		scanf_s("%d", &id);
		Athlete* ath = get_athlete(AthHashTable, id);
		if (ath == NULL)
		{
			printf("找不到运动员");
			break;
		}
		//输出运动员信息
		printf("运动员姓名: %s\n", ath->name);
		printf("运动员id: %s\n", ath->id);
		printf("运动员组织: %s\n", ath->organization);
		for (int i = 0; i < 3; i++)
		{
			printf("参赛项目编号：%d,成绩%d\n", ath->events[i][0], ath->events[i][1]);
		}

		printf("以上为运动员信息！\n");
		//end

		printf("\n0.退出系统  1.返回信息查询\n");
		printf("请输入你的选择:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
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

//打印竞赛的所有信息
void view_raceitem()
{
	for (int i = 0; i < RaceItemTable->capacity; i++)
	{
		REntry* entry = RaceItemTable->table[i];
		while(entry)
		{
			//raceitem in entrynode
			RaceItem* race = entry->value;
			printf("项目名称：%s", race->name);
			printf("    项目id：%d", race->eventsID);
			if(race->Athlete->size<setting.minimumNums)
			{
				printf("    取消\n");
			}
			else {
				printf("    项目最大人数：%d", race->Size);
				printf("    比赛场地%d", race->eventplace);
				printf("    参赛人员信息（id，name）");
				for (int j = 0; j < race->Athlete->size; j++)
				{
					printf("(%s,%s)\n", race->Athlete->data[j]->id, race->Athlete->data[j]->name);
				}
			}
			entry = entry->next;
		}
	}
}

//打印田赛的所有信息
void view_trackitem()
{
	for (int i = 0; i < TrackItemTable->capacity; i++)
	{
		TEntry* entry = TrackItemTable->table[i];
		while (entry)
		{
			//raceitem in entrynode
			TrackItem* track = entry->value;
			
			printf("项目名称：%s", track->name);
			printf("  项目id：%d", track->eventsID);
			if(track->Athlete->size<setting.minimumNums)
			{
				printf("    取消\n");
			}
			else{
			printf("    项目最大人数：%d", track->Size);
			printf("    比赛场地%d", track->eventplace);
			printf("    参赛人员信息（id，name）");

			for (int j = 0; j < track->Athlete->size; j++)
			{
				printf("(%s,%s)\n", track->Athlete->data[j]->id, track->Athlete->data[j]->name);
			}
			}
			entry = entry->next;
		}
	}
}

// 查看比赛项目(结束报名后的项目发布)
int CompetitionInformation(int flag) {
	// 1.查看全部

	// 2.查看田赛
	
	// 3.查看竞赛

	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回信息查询  1.查看全部  2.查看田赛  3.查看竞赛\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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
		// 打印田赛和竞赛
		view_trackitem();
		view_raceitem();
		printf("\n0.退出系统  1.返回比赛项目查询\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1 > 1) {
			printf("输入错误，请重新输入:");
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
		// 打印田赛项目
		view_trackitem();
		printf("\n");
		printf("\n0.退出系统  1.返回比赛项目查询\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
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
		// 打印竞赛项目
		view_raceitem();
		printf("\n");
		printf("\n0.退出系统  1.返回比赛项目查询\n");
		printf("请输入你的选择:");
		int choice_3;
		scanf_s("%d", &choice_3);
		setbuf(stdin, NULL);
		while (choice_3 < 0 || choice_3>1) {
			printf("输入错误，请重新输入:");
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

// 查看成绩
int CheckScore(int flag) {
	// 1.查看田赛成绩
	// 2.查看竞赛成绩
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看田赛成绩  2.查看竞赛成绩\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
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
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice;
		scanf_s("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
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

// 查看田赛成绩
int TrackItemScore(int flag) {
	// 1.按比赛项目查看成绩
	// 2.按参赛组织查看成绩
	// 3.按运动员查看成绩
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.按比赛项目查看成绩  2.按参赛组织查看成绩  3.按运动员查看成绩\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose > 3) {
		printf("输入错误，请重新输入:");
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
		// 输出比赛项目成绩
		{
			system(CLEARCOMMAND);
			int itemID;
			printf("请输入你要查询的比赛项目编号:");
			scanf_s("%d",&itemID);
			
			after_checkTrackItemScore(flag);
		}
		break;
	case 2:
		// 输出参赛组织成绩
		{
			system(CLEARCOMMAND);
			int orgID;
			printf("请输入你要查询的参赛组织编号:");
			scanf_s("%d",&orgID);

			after_checkTrackItemScore(flag);
		}
		break;
	case 3:
		// 通过哈希表查找输出运动员成绩
		{
			system(CLEARCOMMAND);
			int id;
			printf("输入运动员id:");
			scanf_s("%d", &id);
			Athlete* ath = get_athlete(AthHashTable, id);
			if (ath == NULL)
			{
				printf("找不到运动员");
				break;
			}
			//输出运动员信息
			printf("运动员姓名: %s\n", ath->name);
			printf("运动员id: %s\n", ath->id);
			printf("运动员组织: %s\n", ath->organization);
			for (int i = 0; i < 3; i++)
			{
				if(ath->events[i][0]/100 == 1){
					continue;
				}
				else{
					printf("参赛项目编号：%d,成绩%d\n", ath->events[i][0], ath->events[i][1]);
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

// 查看竞赛成绩
int RaceItemScore(int flag) {
	// 1.按比赛项目查看成绩
	// 2.按参赛组织查看成绩
	// 3.按运动员查看成绩
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.按比赛项目查看成绩  2.按参赛组织查看成绩  3.按运动员查看成绩\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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
		// 输出比赛项目成绩
		{
			system(CLEARCOMMAND);
			int itemID;
			printf("请输入你要查询的比赛项目编号:");
			scanf_s("%d",&itemID);
			
			TrackScoreRank();
			RaceScoreRank();
			print_Rank(itemID);

			after_checkRaceItemScore(flag);
		}
		break;
	case 2:
		// 输出参赛组织成绩
		{
			system(CLEARCOMMAND);
			int orgID;
			printf("请输入你要查询的参赛组织编号:");
			scanf_s("%d",&orgID);

			after_checkRaceItemScore(flag);

		}
		break;
	case 3:
		// 通过哈希表查找输出运动员成绩
		{
			system(CLEARCOMMAND);
			int athID;
			printf("请输入你要查询的运动员编号:");
			scanf_s("%d",&athID);
			int id;
			printf("输入运动员id:");
			scanf_s("%d", &id);
			Athlete* ath = get_athlete(AthHashTable, id);
			if (ath == NULL)
			{
				printf("找不到运动员");
				break;
			}
			//输出运动员信息
			printf("运动员姓名: %s\n", ath->name);
			printf("运动员id: %s\n", ath->id);
			printf("运动员组织: %s\n", ath->organization);
			for (int i = 0; i < 3; i++)
			{
				if(ath->events[i][0]/100 == 2){
					continue;
				}
				else{
					printf("参赛项目编号：%d,成绩%d\n", ath->events[i][0], ath->events[i][1]);
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

// 查看得分
int CheckGoal(int flag) {
	// 1.查看组织得分情况
	// 2.查看运动员得分
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.查看组织得分  2.查看运动员得分\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose > 3) {
		printf("输入错误，请重新输入:");
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

// 查看组织得分
int CheckOrganizationGoal(int flag) {
	// 1.正序输出
	// 2.倒序输出
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	int **score =(int**)malloc(sizeof(int*) * 8 );
	for (int i = 0; i < 8; i++)
	{
		score[i] = (int*)malloc(sizeof(int) * 2);
	}
	printf("\n0.返回上一层  1.正序输出  2.倒序输出\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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
		// 正序输出数据
		//TODO::计算组织得分
		for (size_t i = 0; i < 8; i++)
		{
			score[i][0] = i + 1;
			score[i][1] = calc_total_score(organization->data[i + 1].ath_map->root);
		}

		organization_rank(score, 8, -1);



		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("输入错误，请重新输入:");
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
		// 倒序输出数据
		for (size_t i = 0; i < 8; i++)
		{
			score[i][0] = i + 1;
			score[i][1] = calc_total_score(organization->data[i + 1].ath_map->root);
		}

		organization_rank(score, 8, 1);

		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
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

// 查看全部运动员得分
int CheckAthleteGoal(int flag) {
	// 1.正序输出
	// 2.倒序输出
	// 0.返回上一层
	system(CLEARCOMMAND);
	int choose;
	printf("\n0.返回上一层  1.正序输出  2.倒序输出\n");
	printf("请输入你的选择:");
	scanf_s("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
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
		// 正序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf_s("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("输入错误，请重新输入:");
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
		// 倒序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf_s("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
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

// 查看系统设置
void Settings() {
	FILE* fp;
	int flag = fopen_s(&fp,"Setting.txt","r+");
	system(CLEARCOMMAND);
	printf("当前设置：\n");
	printf("项目最小取消人数:  %d人\n", setting.minimumNums);
	for (int i = 0; i < 6; i++)
	{
		printf("第%d名得分：%d\n", i + 1, setting.Rankscores[i]);
	}
	system("pause");
	int choice;
	printf("请输入需要修改的栏目\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
		case 1:
			printf("请输入修改后的最小参赛人数:");
			scanf_s("%d", &setting.minimumNums);
		break;
		case 2:
			printf("请依次输入1-6名的得分权重:\n");
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
