#include <stdio.h>
#include <stdlib.h>
void SuperAdministrator(void);
void Administrator(void);
void visitor(void);
void Announcement(void);
void Apply(void);
void Program(void);
void Information(void);
void SeowonInformation(void);
void AthleteInformation(void);
void CompetitionInformation(void);
void CheckScore(void);
void FieldScore(void);
void ContestScore(void);
void CheckGoal(void);
void CheckSeowonGoal(void);
void CheckAthleteGoal(void);
void SetCompetition(void);
void Setting(void);


// ��������Ա����
void SuperAdministrator() {

	
	
	//1.�޸�ϵͳ����

	//2.������Ŀ����

	//3.���������
	
}

// ����Ա����
void Administrator() {
	//1.��������

	//2.��ɾ�Ĳ�����˶�Ա��Ϣ

	//3.

}

// �οͽ���
void visitor() {
	//�鿴���

}

// ������Ŀ����(ȫ����Ŀ����)
void Announcement() {

}

// �˶�Ա����
void Apply() {

}

// �鿴�����
void Program() {

}

// ������Ϣ��ѯ
void Information() {
	// �鿴������Ժ��Ϣ
	// �鿴�˶�Ա��Ϣ
	// �鿴������Ŀ
}

// �鿴������Ժ��Ϣ
void SeowonInformation() {

}

// �鿴�˶�Ա��Ϣ
void AthleteInformation() {

}

// �鿴������Ŀ(�������������Ŀ����)
void CompetitionInformation() {
}

// �鿴�ɼ�
void CheckScore() {
	// �鿴�����ɼ�
	// �鿴�����ɼ�
}

// �鿴�����ɼ�
void FieldScore() {
	// ��������Ŀ�鿴�ɼ�
	// ��������Ժ�鿴�ɼ�
	// ���˶�Ա�鿴�ɼ�
}

// �鿴�����ɼ�
void ContestScore() {
	// ��������Ŀ�鿴�ɼ�
	// ��������Ժ�鿴�ɼ�
	// ���˶�Ա�鿴�ɼ�
}

// �鿴�÷ֽ���
void CheckGoal() {
	// �鿴��Ժ�÷����
	// �鿴�˶�Ա�÷�
}

// �鿴��Ժ�÷�
void CheckSeowonGoal() {

}

// �鿴�˶�Ա�÷�
void CheckAthleteGoal() {

}

// �������
void CheckAgain() {

}

// ������Ŀ����
void SetCompetition() {

}

// ϵͳ����
void Setting() {

}

int main() {
	int choose;
	printf("Who you are?");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("�����������������:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 1:
		SuperAdministrator();
		system("pause");
		break;
	case 2:
		Administrator();
		system("pause");

		break;
	case 3:
		visitor();
		system("pause");

		break;
	default:
		break;
	}
}