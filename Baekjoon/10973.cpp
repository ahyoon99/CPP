#include <iostream>
using namespace std;

int arr[10001];

bool prev_permutation(int* a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) {
		i--;
	}
	if (i <= 0) {	// 이전 순열 없음
		return false;
	}

	int j = n - 1;
	while (a[i - 1] <= a[j]) {
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
		cin >> arr[i];
	}

	if (prev_permutation(arr, N)) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}


	return 0;

}