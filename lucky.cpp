#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char arr[10];
	int left = 0, right = 0;
	cin >> arr;
	int size = strlen(arr);
	if (size % 2 == 0) {
		for (int i = 0; i < size / 2; i++) {
			left += arr[i]-48;
			right += arr[(size /2)+ i]-48;
		}
		if (left == right) printf("lucky");
		else printf("ready");
	}
	else printf("ready");
	return 0;
}