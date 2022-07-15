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
	printf("프로그램 퀴즈 게임\n\n---------------------\n환영합니다.\n\n");
	printf("퀴즈를 시작하세요\n\n---------------------\n---------------------\n");
	printf("이러닝 과제 입니다 !!!!!!!!!\n---------------------\n---------------------\n");
	printf("> 게임 시작은 S\n> 점수 보기 V\n> 도움말 H\n> 중단은 Q를 클릭해 주세요 ");
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
	printf("\n\n\n\n\n\n\n\n\t\t이름을 입력하시오 : ");
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
	printf("환영합니다\n\n");
	printf("%s님 퀴즈 게임입니다\n", game[count-1].name);
	printf("-----------------------\n\n1. 문제풀이는 사지선다를 선택하도록 되어 있습니다.\n\n");
	printf("2. A, B, C, D 의 옵션중 원하는 답을 선택하시면 됩니다.\n\n꼭 정답을 마추셔서 100점을 취득하세요 ^.^\n\n게임 시작은  Y !\n");
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
			printf("\n1 + 1 = ? \n정답 : ");
			scanf_s("%d", &b);
			if (b == 2)
				score_ += 20;
			printf("\n물고기의 반대말은? \n정답 : ");
			scanf_s("%s", a, 10);
			if (strcmp(a,"불고기") == 0)
				score_ += 20;
			printf("\n처음 만나는 소가 하는 말은? \n정답 : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "반갑소") == 0)
				score_ += 20;
			printf("\n병아리가 잘 먹는 약은? \n정답 : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "삐약") == 0)
				score_ += 20;
			printf("\n비가 자기 소개할 때 하는 말은? \n정답 : ");
			scanf_s("%s", a, 10);
			if (strcmp(a, "나비야") == 0)
				score_ += 20;
			if (score_ < 80)
				printf("재시험 입니다!!");
		}
		game[count-1].score = score_;
		printf("\n\n축하힙니다.\n");
		if (score_ == 100)
			printf("만점입니다!!!!!\n");
		printf("최고입니다. %d\n게임을 계속하려면 Y를 입력하세요\n메인으로 가려면 아무키나 입력하세요\n ", score_);
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
		printf("%10s 저장된 점수 %d\n\n", game[i].name, game[i].score);
	}
	printf("*******************************************\n\n");
	quiz = fopen("quiz.txt", "w");
	fprintf(quiz,"*******************************************\n\n");
	for (int i = 0; i < count; i++) {
		fprintf(quiz,"%10s 저장된 점수 %d\n\n", game[i].name, game[i].score);
	}
	fprintf(quiz,"*******************************************\n\n");
	fclose(quiz);
}