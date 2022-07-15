#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;

void move(int num1, int num2) {
	if (num1 + 2 < 8) {
		if (num2 + 1 < 8)
			cnt++;
		if (num2 - 1 >= 0)
			cnt++;
	}
	if (num1 - 2 >= 0) {
		if (num2 + 1 < 8)
			cnt++;
		if (num2 - 1 >= 0)
			cnt++;
	}
}

int main() {
	char cn;
	int n = 0, pos=0;
	char position[8] = { 'a','b','c','d','e','f','g','h' };
	scanf("%c%d", &cn, &n);
	n-=1;
	while (1) {
		if (cn == position[pos]) {
			break;
		}
		pos++;
	}

	move(pos, n);
	move(n, pos);
	printf("%d", cnt);
	return 0;
}