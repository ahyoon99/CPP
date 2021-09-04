#include <iostream>
using namespace std;

int arr[9];

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

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << "\n";

	while (next_permutation(arr, N)) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}