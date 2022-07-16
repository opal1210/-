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
	printf("#�����͸� �Է��ϼ���(�̸��� q�� �Է��ϸ� �Է��� �����մϴ�.\n");
	printf("#�ִ� 5���� �����͸� �Է��Ҽ� �ֽ��ϴ�.\n");

	struct employee data[5] = { 0 };

	int max_money = 0, total = 0;
	int i, j = 0;

	for (int k = 0; k < 1;) {
		for (i = 0; i < 5; i++) {
			printf("�̸�: ");
			scanf_s("%s", data[i].name, 10);
			if (data[i].name[0] == 'q' && data[i].name[1] == '\0')
				break;
			printf("��ȭ��ȣ: ");
			scanf_s("%s", data[i].phone, 15);
			printf("�ٹ��ð�: ");
			scanf_s("%d", &data[i].hour);
			printf("�ð��� �ӱ�: ");
			scanf_s("%d", &data[i].hour_money);
			total += (data[i].hour * data[i].hour_money);
			data[i].total_money = (data[i].hour * data[i].hour_money);
			j++;
			printf("\n");
		}
		if (i != 0) {
			max_money = find_exp_employee(data, j);
			printf("#�Է��� ���� �մϴ�.\n");
			printf("#�Էµ� ������ ���� ��� %d�� �Դϴ�.\n", j);
			printf("#�ð��� �ӱ��� ���� ���� ������ %d���� �޴� %s �Դϴ�.\n", max_money, max_name);
			printf("#���� �����ؾ��� �� ������ӱ��� �հ�� %d�� �Դϴ�.", total);
			sort_data(data, j);
			money_file(data, j);
			return 0;
		}
		else
			printf("�ٽ� �Է����ּ���\n");
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