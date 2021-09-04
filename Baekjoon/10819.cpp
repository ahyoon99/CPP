#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];

bool next_permutation(int* a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		i--;
	}
	if (i <= 0) {
		return false;
	}

	int j = n - 1;
	while (a[i - 1] >= a[j]) {
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

int calculate(int* a, int n) {
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		result += abs(a[i] - a[i + 1]);
	}
	return result;
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int max = calculate(arr, N);

	while (next_permutation(arr, N)) {
		if (max < calculate(arr, N)) {
			max = calculate(arr, N);
		}
	}
	
	cout << max << "\n";

	return 0;
}