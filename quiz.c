#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void name_input(struct game game[], int num1);
void explain(int num1);
void game_start(struct game game[]);
void scoreborad(struct game game[]);

int count = 0;

struct game {
	char name[10];
	int score;
}game[100];

void main() {
	char start;
	printf("���α׷� ���� ����\n\n---------------------\nȯ���մϴ�.\n\n");
	printf("��� �����ϼ���\n\n---------------------\n---------------------\n");
	printf("�̷��� ���� �Դϴ� !!!!!!!!!\n---------------------\n---------------------\n");
	printf("> ���� ������ S\n> ���� ���� V\n> ���� H\n> �ߴ��� Q�� Ŭ���� �ּ��� ");
	scanf_s("%c", &start);
	switch (start)
	{
	case 'S': case 's':
		name_input(game,0);
		break;
	case 'V':case 'v':
		scoreborad(game);
		break;
	case 'H':case 'h':
		explain(1);
		break;
	case 'Q':case 'q':
		exit;
	}

}

void name_input(struct game game[],int num1) {
	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t�̸��� �Է��Ͻÿ� : ");
	scanf_s("%s", game[count].name, 10);
	count++;
	if (num1 == 1)
		game_start(game);
	else
		explain(0);
}

void explain(int num1) {
	char a;
	system("cls");
	printf("ȯ���մϴ�\n\n");
	printf("%s�� ���� �����Դϴ�\n", game[count-1].name);
	printf("-----------------------\n\n1. ����Ǯ�̴� �������ٸ� �����ϵ��� �Ǿ� �ֽ��ϴ�.\n\n");
	printf("2. A, B, C, D �� �ɼ��� ���ϴ� ���� �����Ͻø� �˴ϴ�.\n\n�� ������ ���߼ż� 100���� ����ϼ��� ^.^\n\n���� ������  Y !\n");
	for (int i = 0; i < 1;) {
		a = getch();
		if (a == 'Y' || a == 'y') {
			if (num1 == 1)
				name_input(game,1);
			else
				game_start(game);
		}	
	}
}

void game_start(struct game game[]) {
	system("cls");
	char a[10],op;
	int score_ = 0,b;
	for (int i = 0;i < 1;) {
		while (score_ < 80) {
			score_ = 0;
			printf("\n1 + 1 = ? \n���� : ");
			scanf_s("%d", &b);
			if (b == 2)
				score_ += 20;
			printf("\n������� �ݴ븻��? \n���� : ");
			scanf_s("%s", a, 10);
			if (strcmp(a,"�Ұ��") == 0)
				score_ += 20;
			printf("\nó�� ������ �Ұ� �ϴ� ����? \n���� : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "�ݰ���") == 0)
				score_ += 20;
			printf("\n���Ƹ��� �� �Դ� ����? \n���� : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "�߾�") == 0)
				score_ += 20;
			printf("\n�� �ڱ� �Ұ��� �� �ϴ� ����? \n���� : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "�����") == 0)
				score_ += 20;
			if (score_ < 80)
				printf("����� �Դϴ�!!");
		}
		game[count-1].score = score_;
		printf("\n\n�������ϴ�.\n");
		if (score_ == 100)
			printf("�����Դϴ�!!!!!\n");
		printf("�ְ��Դϴ�. %d\n������ ����Ϸ��� Y�� �Է��ϼ���\n�������� ������ �ƹ�Ű�� �Է��ϼ���\n ", score_);
		op = getche();
		if (op == 'y' || op == 'Y')
			name_input(game, 1);
		else
			main();
	}
}

void scoreborad(struct game game[]) {
	FILE* quiz;
	printf("*******************************************\n\n");
	for (int i = 0; i < count; i++) {
		printf("%10s ����� ���� %d\n\n", game[i].name, game[i].score);
	}
	printf("*******************************************\n\n");
	quiz = fopen("quiz.txt", "w");
	fprintf(quiz,"*******************************************\n\n");
	for (int i = 0; i < count; i++) {
		fprintf(quiz,"%10s ����� ���� %d\n\n", game[i].name, game[i].score);
	}
	fprintf(quiz,"*******************************************\n\n");
	fclose(quiz);
}