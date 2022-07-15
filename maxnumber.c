#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0, m = 0, k = 0, max1 =0, max2 =0 ,sum =0;
	scanf_s("%d %d %d", &size, &m, &k);
	int* num = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size;i++)
		scanf_s("%d", &num[i]);
	for (int i = 0; i < size; i++) {
		if (max1 < num[i]) {
			max2 = max1;
			max1 = num[i];
		}
		else if (num[i] > max2)
			max2 = num[i];
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < k;i++) {
			sum += max1;
			j++;
		}
		sum += max2;
	}
	printf("%d", sum);
	

}
