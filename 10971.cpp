// 1번째 방법
#include <iostream>
using namespace std;

int W[11][11] = { 0, };
int arr[11] = { 0, };

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
		arr[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	int min = 4000000;

	do {

		bool check = true;
		int sum = 0;

		for (int i = 0; i < N-1; i++) {
			if (W[arr[i]][arr[i + 1]] != 0) {
				sum += W[arr[i]][arr[i + 1]];
			}
			else {
				check = false;
				break;
			}
		}

		if (check && W[arr[N - 1]][arr[0]] != 0) {
			sum += W[arr[N - 1]][arr[0]];
			if (min > sum) {
				min = sum;
			}
		}
		else {
			continue;
		}
	} while (next_permutation(arr, N));

	cout << min << "\n";

	return 0;
}


// 2번째 방법
//#include <iostream>
//using namespace std;
//
//int W[11][11] = { 0, };
//int arr[11] = { 0, };
//
//bool next_permutation(int* a, int n) {
//	int i = n - 1;
//	while (i > 0 && a[i - 1] >= a[i]) {
//		i--;
//	}
//	if (i <= 0) {
//		return false;
//	}
//
//	int j = n - 1;
//	while (a[i - 1] >= a[j]) {
//		j--;
//	}
//	swap(a[i - 1], a[j]);
//
//	j = n - 1;
//	while (i < j) {
//		swap(a[i], a[j]);
//		i++;
//		j--;
//	}
//	return true;
//}
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		arr[i] = i;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> W[i][j];
//		}
//	}
//
//	int min = 4000000;
//
//	do {
//
//		if (arr[0] != 0) {	// 시작점을 0으로 고정!
//			break;
//		}
//
//		bool check = true;
//		int sum = 0;
//
//		for (int i = 0; i < N - 1; i++) {
//			if (W[arr[i]][arr[i + 1]] != 0) {
//				sum += W[arr[i]][arr[i + 1]];
//			}
//			else {
//				check = false;
//				break;
//			}
//		}
//
//		if (check && W[arr[N - 1]][arr[0]] != 0) {
//			sum += W[arr[N - 1]][arr[0]];
//			if (min > sum) {
//				min = sum;
//			}
//		}
//		else {
//			continue;
//		}
//	} while (next_permutation(arr, N));
//
//	cout << min << "\n";
//
//	return 0;
//}