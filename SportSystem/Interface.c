
// 界面
// 查看田赛成绩和竞赛成绩未完成
// 比赛项目设置以及系统设置未完成
// 比赛项目设置由人工输入项目，通过SuperAdmin发布查看

#include <stdio.h>
#include <stdlib.h>
#include "forlogin.h"
#include "Interface.h"

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
void SetCompetition(void);
void Setting(void);


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
	int SAChoose;
	printf("\n");
	printf("0.退出  1.参赛项目发布(全部项目发布)  2.参赛信息查询  3.运动员报名  4.查看秩序册  5.查看比赛项目  6.查看成绩  7.查看得分  8.系统设置\n");
	printf("请输入你的选择:");
	scanf("%d", &SAChoose);
	setbuf(stdin, NULL);
	while (SAChoose < 0 || SAChoose>9) {
		printf("输入错误，请重新输入:");
		scanf("%d", &SAChoose);
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
		SetCompetition();
		break;
	case 9:
		Setting();
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
	int AChoose;
	printf("0.退出  1.运动员报名  2.查看秩序册  3.查看比赛项目  4.参赛信息查询  5.查看成绩  6.查看得分\n");
	printf("请输入你的选择:");
	scanf("%d", &AChoose);
	setbuf(stdin, NULL);
	while (AChoose < 0 || AChoose>9) {
		printf("输入错误，请重新输入:");
		scanf("%d", &AChoose);
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
	int VChoose;
	printf("0.退出  1.查看成绩  2.查看得分\n");
	printf("请输入你的选择:");
	scanf("%d", &VChoose);
	setbuf(stdin, NULL);
	while (VChoose < 0 || VChoose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &VChoose);
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
	int choose;
	printf("0.返回上一层  1.确认发布全部项目  2.比赛项目设置\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>2) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		SuperAdministrator();
		break;
	case 1:
		printf("已发布全部项目\n");
		Announcement();
		break;
	case 2:
		SetCompetition();
		break;
	default:
		break;
	}
}

// 运动员报名界面
int Apply(int flag) {
	// 1.运动员报名
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.运动员报名\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
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
		break;
	case 1:
		if (flag == 1) {
			AthleteApply(1);
		}
		else if (flag == 2) {
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
	char org[30], name[20];
	int Item;
	printf("请输入你的组织:");
	scanf("%s", &org);
	printf("请输入你的名字:");
	scanf("%s", &name);
	pritnf("请输入你参加的项目:");
	scanf("%d",&Item );
	int choose;
	printf("0.退出系统 1.返回主菜单\n");
	printf("输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		exit(0);
		break;
	case 1:
		if (flag == 1) {
			SuperAdministrator();
		}
		else if (flag == 2) {
			Administrator();
		}
		break;
	default:
		break;
	}
	return 0;
}

// 查看秩序册
int Program(int flag) {
	// 1.查看秩序册
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.查看测序册\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
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
		break;
	case 1:
		//打印出秩序册(函数)
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				SuperAdministrator();
			}
			else if (flag == 2) {
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
	int choose;
	printf("0.返回上一层  1.查看参赛组织信息  2.查看运动员信息  3.查看比赛项目\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
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
	case 1:
		if (flag == 1) {
			OrganizationInformation(1);
		}
		else if (flag == 2) {
			OrganizationInformation(2);
		}
		break;
	case 2:
		if (flag == 1) {
			AthleteInformation(1);
		}
		else if (flag == 2) {
			AthleteInformation(2);
		}
		break;
	case 3:
		if (flag == 1) {
			CompetitionInformation(1);
		}
		else if (flag == 2) {
			CompetitionInformation(2);
		}
		break;
	default:
		break;
	}
	return 0;
}

// 查看参赛组织信息
int OrganizationInformation(int flag) {
	// 1.排序输出
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.查看\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			Information(1);
		}
		else if (flag == 2) {
			Information(2);
		}
		break;
	case 1:
		// 打印文件
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				Information(1);
			}
			else if (flag == 2) {
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
	// 1.排序输出
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.查看\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			Information(1);
		}
		else if (flag == 2) {
			Information(2);
		}
		break;
	case 1:
		// 通过哈希表查找
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice);
			setbuf(stdin, NULL);
		}
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				Information(1);
			}
			else if (flag == 2) {
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

// 查看比赛项目(结束报名后的项目发布)
int CompetitionInformation(int flag) {
	// 1.查看全部
	// 2.查看田赛
	// 3.查看竞赛
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.查看全部  2.查看田赛  3.查看竞赛\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			Information(1);
		}
		else if (flag == 2) {
			Information(2);
		}
		break;
	case 1:
		// 打印文件
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CompetitionInformation(1);
			}
			else if (flag == 2) {
				CompetitionInformation(2);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		// 打印田赛项目
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CompetitionInformation(1);
			}
			else if (flag == 2) {
				CompetitionInformation(2);
			}
			break;
		default:
			break;
		}
		break;
	case 3:
		// 打印竞赛项目
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_3;
		scanf("%d", &choice_3);
		setbuf(stdin, NULL);
		while (choice_3 < 0 || choice_3>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_3);
			setbuf(stdin, NULL);
		}
		switch (choice_3) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CompetitionInformation(1);
			}
			else if (flag == 2) {
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
	int choose;
	printf("0.返回上一层  1.查看田赛成绩  2.查看竞赛成绩\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
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
			TrackItemScore(1);
		}
		else if (flag == 2) {
			TrackItemScore(2);
		}
		else if (flag == 3) {
			TrackItemScore(3);
		}
		break;
		break;
	case 2:
		if (flag == 1) {
			RaceItemScore(1);
		}
		else if (flag == 2) {
			RaceItemScore(2);
		}
		else if (flag == 3) {
			RaceItemScore(3);
		}
		break;
	default:
		break;
	}
	return 0;
}

// 查看田赛成绩
int TrackItemScore(int flag) {
	// 1.按比赛项目查看成绩
	// 2.按参赛组织查看成绩
	// 3.按运动员查看成绩
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.按比赛项目查看成绩  2.按参赛组织查看成绩  3.按运动员查看成绩\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			CheckScore(1);
		}
		else if (flag == 2) {
			CheckScore(2);
		}
		else if (flag == 3) {
			CheckScore(3);
		}
		break;
	case 1:
		// 输出比赛项目成绩
		break;
	case 2:
		// 输出参赛组织成绩
		break;
	case 3:
		// 通过哈希表查找输出运动员成绩
		break;
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
	int choose;
	printf("0.返回上一层  1.按比赛项目查看成绩  2.按参赛组织查看成绩  3.按运动员查看成绩\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			CheckScore(1);
		}
		else if (flag == 2) {
			CheckScore(2);
		}
		else if (flag == 3) {
			CheckScore(3);
		}
		break;
	case 1:
		// 输出比赛项目成绩
		break;
	case 2:
		// 输出参赛组织成绩
		break;
	case 3:
		// 通过哈希表查找输出运动员成绩
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
	int choose;
	printf("0.返回上一层  1.查看组织得分情况  2.查看运动员得分\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
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
			CheckOrganizationGoal(1);
		}
		else if (flag == 2) {
			CheckOrganizationGoal(2);
		}
		else if (flag == 3) {
			CheckOrganizationGoal(3);
		}
		break;
	case 2:
		if (flag == 1) {
			CheckAthleteGoal(1);
		}
		else if (flag == 2) {
			CheckAthleteGoal(2);
		}
		else if (flag == 3) {
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
	int choose;
	printf("0.返回上一层  1.正序输出  2.倒序输出\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			CheckScore(1);
		}
		else if (flag == 2) {
			CheckGoal(2);
		}
		else if (flag == 3) {
			CheckGoal(3);
		}
		break;
	case 1:
		// 正序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CheckOrganizationGoal(1);
			}
			else if (flag == 2) {
				CheckOrganizationGoal(2);
			}
			else if (flag == 3) {
				CheckOrganizationGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		// 倒序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CheckOrganizationGoal(1);
			}
			else if (flag == 2) {
				CheckOrganizationGoal(2);
			}
			else if (flag == 3) {
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

// 查看运动员得分
int CheckAthleteGoal(int flag) {
	// 1.正序输出
	// 2.倒序输出
	// 0.返回上一层
	int choose;
	printf("0.返回上一层  1.正序输出  2.倒序输出\n");
	printf("请输入你的选择:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		if (flag == 1) {
			CheckScore(1);
		}
		else if (flag == 2) {
			CheckGoal(2);
		}
		else if (flag == 3) {
			CheckGoal(3);
		}
		break;
	case 1:
		// 正序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_1);
			setbuf(stdin, NULL);
		}
		switch (choice_1) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CheckAthleteGoal(1);
			}
			else if (flag == 2) {
				CheckAthleteGoal(2);
			}
			else if (flag == 3) {
				CheckAthleteGoal(3);
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		// 倒序输出数据
		printf("\n0.退出系统  1.返回\n");
		printf("请输入你的选择:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("输入错误，请重新输入:");
			scanf("%d", &choice_2);
			setbuf(stdin, NULL);
		}
		switch (choice_2) {
		case 0:
			exit(0);
			break;
		case 1:
			if (flag == 1) {
				CheckAthleteGoal(1);
			}
			else if (flag == 2) {
				CheckAthleteGoal(2);
			}
			else if (flag == 3) {
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

// 比赛项目设置
void SetCompetition() {

}

// 系统设置
void Setting() {

}