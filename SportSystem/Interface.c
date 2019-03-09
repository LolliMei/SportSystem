
// ����
// �鿴�����ɼ��;����ɼ�δ���
// ������Ŀ�����Լ�ϵͳ����δ���
// ������Ŀ�������˹�������Ŀ��ͨ��SuperAdmin�����鿴

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
	int SAChoose;
	printf("\n");
	printf("0.�˳�  1.������Ŀ����(ȫ����Ŀ����)  2.������Ϣ��ѯ  3.�˶�Ա����  4.�鿴�����  5.�鿴������Ŀ  6.�鿴�ɼ�  7.�鿴�÷�  8.ϵͳ����\n");
	printf("���������ѡ��:");
	scanf("%d", &SAChoose);
	setbuf(stdin, NULL);
	while (SAChoose < 0 || SAChoose>9) {
		printf("�����������������:");
		scanf("%d", &SAChoose);
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
		SetCompetition();
		break;
	case 9:
		Setting();
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
	int AChoose;
	printf("0.�˳�  1.�˶�Ա����  2.�鿴�����  3.�鿴������Ŀ  4.������Ϣ��ѯ  5.�鿴�ɼ�  6.�鿴�÷�\n");
	printf("���������ѡ��:");
	scanf("%d", &AChoose);
	setbuf(stdin, NULL);
	while (AChoose < 0 || AChoose>9) {
		printf("�����������������:");
		scanf("%d", &AChoose);
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
	int VChoose;
	printf("0.�˳�  1.�鿴�ɼ�  2.�鿴�÷�\n");
	printf("���������ѡ��:");
	scanf("%d", &VChoose);
	setbuf(stdin, NULL);
	while (VChoose < 0 || VChoose>1) {
		printf("�����������������:");
		scanf("%d", &VChoose);
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
	int choose;
	printf("0.������һ��  1.ȷ�Ϸ���ȫ����Ŀ  2.������Ŀ����\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>2) {
		printf("�����������������:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 0:
		SuperAdministrator();
		break;
	case 1:
		printf("�ѷ���ȫ����Ŀ\n");
		Announcement();
		break;
	case 2:
		SetCompetition();
		break;
	default:
		break;
	}
}

// �˶�Ա��������
int Apply(int flag) {
	// 1.�˶�Ա����
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�˶�Ա����\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
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

// �˶�Ա����
int AthleteApply(int flag) {                     // ����flagֵ�Ӷ�ȷ�����ؽ���
	char org[30], name[20];
	int Item;
	printf("�����������֯:");
	scanf("%s", &org);
	printf("�������������:");
	scanf("%s", &name);
	pritnf("��������μӵ���Ŀ:");
	scanf("%d",&Item );
	int choose;
	printf("0.�˳�ϵͳ 1.�������˵�\n");
	printf("�������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
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

// �鿴�����
int Program(int flag) {
	// 1.�鿴�����
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴�����\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
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
		//��ӡ�������(����)
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
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


// ������Ϣ��ѯ
int Information(int flag) {
	// 1.�鿴������֯��Ϣ
	// 2.�鿴�˶�Ա��Ϣ
	// 3.�鿴������Ŀ
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴������֯��Ϣ  2.�鿴�˶�Ա��Ϣ  3.�鿴������Ŀ\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
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

// �鿴������֯��Ϣ
int OrganizationInformation(int flag) {
	// 1.�������
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
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
		// ��ӡ�ļ�
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
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

// �鿴�˶�Ա��Ϣ
int AthleteInformation(int flag) {
	// 1.�������
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>1) {
		printf("�����������������:");
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
		// ͨ����ϣ�����
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice;
		scanf("%d", &choice);
		setbuf(stdin, NULL);
		while (choice < 0 || choice>1) {
			printf("�����������������:");
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

// �鿴������Ŀ(�������������Ŀ����)
int CompetitionInformation(int flag) {
	// 1.�鿴ȫ��
	// 2.�鿴����
	// 3.�鿴����
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴ȫ��  2.�鿴����  3.�鿴����\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 0 || choose>3) {
		printf("�����������������:");
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
		// ��ӡ�ļ�
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("�����������������:");
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
		// ��ӡ������Ŀ
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
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
		// ��ӡ������Ŀ
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_3;
		scanf("%d", &choice_3);
		setbuf(stdin, NULL);
		while (choice_3 < 0 || choice_3>1) {
			printf("�����������������:");
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

// �鿴�ɼ�
int CheckScore(int flag) {
	// 1.�鿴�����ɼ�
	// 2.�鿴�����ɼ�
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�鿴�����ɼ�  2.�鿴�����ɼ�\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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

// �鿴�����ɼ�
int TrackItemScore(int flag) {
	// 1.��������Ŀ�鿴�ɼ�
	// 2.��������֯�鿴�ɼ�
	// 3.���˶�Ա�鿴�ɼ�
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.��������Ŀ�鿴�ɼ�  2.��������֯�鿴�ɼ�  3.���˶�Ա�鿴�ɼ�\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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
		// ���������Ŀ�ɼ�
		break;
	case 2:
		// ���������֯�ɼ�
		break;
	case 3:
		// ͨ����ϣ���������˶�Ա�ɼ�
		break;
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
	int choose;
	printf("0.������һ��  1.��������Ŀ�鿴�ɼ�  2.��������֯�鿴�ɼ�  3.���˶�Ա�鿴�ɼ�\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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
		// ���������Ŀ�ɼ�
		break;
	case 2:
		// ���������֯�ɼ�
		break;
	case 3:
		// ͨ����ϣ���������˶�Ա�ɼ�
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
	int choose;
	printf("0.������һ��  1.�鿴��֯�÷����  2.�鿴�˶�Ա�÷�\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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

// �鿴��֯�÷�
int CheckOrganizationGoal(int flag) {
	// 1.�������
	// 2.�������
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�������  2.�������\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("�����������������:");
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
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
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

// �鿴�˶�Ա�÷�
int CheckAthleteGoal(int flag) {
	// 1.�������
	// 2.�������
	// 0.������һ��
	int choose;
	printf("0.������һ��  1.�������  2.�������\n");
	printf("���������ѡ��:");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
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
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_1;
		scanf("%d", &choice_1);
		setbuf(stdin, NULL);
		while (choice_1 < 0 || choice_1>1) {
			printf("�����������������:");
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
		// �����������
		printf("\n0.�˳�ϵͳ  1.����\n");
		printf("���������ѡ��:");
		int choice_2;
		scanf("%d", &choice_2);
		setbuf(stdin, NULL);
		while (choice_2 < 0 || choice_2>1) {
			printf("�����������������:");
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

// ������Ŀ����
void SetCompetition() {

}

// ϵͳ����
void Setting() {

}