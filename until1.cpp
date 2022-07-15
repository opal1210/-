#include <stdio.h>

int main() {
	int n = 0, k = 0, i =0;
	scanf_s("%d %d", &n, &k);
	while (1 != n) {
		if (n % k == 0) {
			n = n / k;
			i++;
		}
		else {
			n -= 1;
			i++;
		}
	}
	
	printf("%d", i);
}