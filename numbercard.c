#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	int m = 0, n = 0, val =0, val1= 0;
	while (1) {
		scanf_s("%d %d", &n, &m);
		if (1 <= n && 100 >= m)
			break;
	}
	int **a = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		a[i] = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			scanf_s("%d", &a[i][j]);
	for (int i = 0; i < n; i++) {
		val = a[i][0];
		for (int j = 0; j < m; j++) {
			if (val > a[i][j]) {
				val = a[i][j];
				val1 = val;
			}
		}
		if (val1 < val)
			val1 = val;
	}
	printf("%d", val1);
	return 0;

}