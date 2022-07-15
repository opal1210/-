#include <stdio.h>

int main() {
	int n = 0 ,row =1 , col = 1;
	char de;
	scanf_s("%d", &n);
	while (1)
	{
		scanf_s(" %c", &de);
		switch (de)
		{
		case 'R':
			col++;
			if (col > n)
				col--;
			continue;
		case 'L':
			col--;
			if (col < 1)
				col++;
			continue;
		case 'U':
			row--;
			if (row < 1)
				row++;
			continue;
		case 'D':
			row++;
			if (row > n)
				row--;
			continue;
		default:
			break;
		}
		break;
	}
	printf("(%d, %d)", row, col);
	return 0;
}