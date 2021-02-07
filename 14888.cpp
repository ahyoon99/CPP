#include <iostream>
#include<algorithm>
using namespace std;

int num[12] = { 0, };
int cal[4];
int arr[11];

bool next_permutation(int* a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		i--;
	}
	if (i <= 0) {
		return false;
	}

	int j = n - 1;
	while (a[i-1] >= a[j]) {
		j--;
	}
	swap(a[i - 1], a[j]);

	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int n = 0;
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
		for (int j = 0; j < cal[i]; j++) {
			arr[n] = i;
			n++;
		}
	}

	int max = -1000000001;
	int min = 1000000001;

	do {
		int result = num[0];
		for (int i = 0; i < N-1; i++) {
			if (arr[i] == 0) {
				result += num[i + 1];
			}
			else if (arr[i] == 1) {
				result -= num[i + 1];
			}
			else if (arr[i] == 2) {
				result *= num[i + 1];
			}
			else if (arr[i] == 3) {
				result /= num[i + 1];
			}
		}

		if (min > result) {
			min = result;
		}
		if (max < result) {
			max = result;
		}

	} while (next_permutation(arr, N-1));

	cout << max << "\n" << min << "\n";

	return 0;
}