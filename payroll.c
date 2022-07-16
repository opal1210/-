#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct employee {
	char name[10];
	char phone[15];
	int hour;
	int hour_money;
	int total_money;
};

char* max_name;
int find_exp_employee(struct employee data[], int total_employee);
void sort_data(struct employee data[], int total_employee);
void money_file(struct employee data[], int total_employee);

int main(void) {
	printf("#데이터를 입력하세요(이름에 q를 입력하면 입력을 종료합니다.\n");
	printf("#최대 5개의 데이터를 입력할수 있습니다.\n");

	struct employee data[5] = { 0 };

	int max_money = 0, total = 0;
	int i, j = 0;

	for (int k = 0; k < 1;) {
		for (i = 0; i < 5; i++) {
			printf("이름: ");
			scanf_s("%s", data[i].name, 10);
			if (data[i].name[0] == 'q' && data[i].name[1] == '\0')
				break;
			printf("전화번호: ");
			scanf_s("%s", data[i].phone, 15);
			printf("근무시간: ");
			scanf_s("%d", &data[i].hour);
			printf("시간당 임금: ");
			scanf_s("%d", &data[i].hour_money);
			total += (data[i].hour * data[i].hour_money);
			data[i].total_money = (data[i].hour * data[i].hour_money);
			j++;
			printf("\n");
		}
		if (i != 0) {
			max_money = find_exp_employee(data, j);
			printf("#입력을 종료 합니다.\n");
			printf("#입력된 직원의 수는 모두 %d명 입니다.\n", j);
			printf("#시간당 임금이 가장 높은 직원은 %d원을 받는 %s 입니다.\n", max_money, max_name);
			printf("#현재 지불해야할 총 고용자임금의 합계는 %d원 입니다.", total);
			sort_data(data, j);
			money_file(data, j);
			return 0;
		}
		else
			printf("다시 입력해주세요\n");
	}


}

int find_exp_employee(struct employee data[], int total_employee) {
	int i;
	int exp_employee = 0, exp_employee_pay = 0;
	for (i = 0; i < total_employee; i++) {
		if (exp_employee < data[i].hour_money) {
			exp_employee = data[i].hour_money;
			max_name = data[i].name;
		}
	}
	return exp_employee;
}

void money_file(struct employee data[], int total_employee) {
	FILE* foc;
	foc = fopen("money.txt", "w");
	fprintf(foc, "Name     Phone        Working Hour    pay/hour       Total pay\n");
	fprintf(foc, "=============================================================================\n");
	int i;
	for (i = 0; i < total_employee; i++) {
		fprintf(foc, "%4s%16s%12d%19d%16d\n", data[i].name, data[i].phone, data[i].hour, data[i].hour_money, data[i].total_money);
	}
	fprintf(foc, "========================================================================\n");
	fclose(foc);
}

void sort_data(struct employee data[], int total_employee) {
	int i, j;
	struct employee temp;
	for (i = 0; i < total_employee - 1; i++) {
		for (j = i; j < total_employee; j++) {
			if (data[i].total_money < data[j].total_money) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}