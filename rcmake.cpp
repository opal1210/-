#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

int arr[1000000];

int n, m;   

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%2000000000;
    }
    srand(time(NULL));
    int start = 0;
    int end = 1e9;
    int result = 0;
    while (start <= end) {
        long long int total = 0;
        int mid = (end + start) / 2;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) total += arr[i] - mid;
        }
        if (total < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result << '\n';
}