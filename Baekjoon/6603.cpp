#include <iostream>
using namespace std;

int num[13] = { 0, };
int arr[13] = { 0, };

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

	//bool check = true;

	while (true) {
		int N;
		cin >> N;

		if (N == 0) {
			//check = false;
			break;
		}

		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < 6; i++) {
			arr[i] = 0;
		}
		for (int i = 6; i < N; i++) {
			arr[i] = 1;
		}

		do {
			for (int i = 0; i < N; i++) {
				if (arr[i] == 0) {
					cout << num[i] << " ";
				}
			}
			cout << "\n";
		} while (next_permutation(arr, N));
		cout << "\n";
	}
	

	return 0;
}