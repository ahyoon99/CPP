#include <iostream>
using namespace std;

int work[16][2];

int go(int data_size, int idx, int pay, int max) {
	if (idx > data_size) {
		return 0;
	}
	else if (idx == data_size) {
		return pay;
	}

	int med = go(data_size, idx + work[idx][0], pay + work[idx][1], max);
	if (max < med) {
		max = med;
	}
	med = go(data_size, idx + 1, pay, max);
	if (max < med) {
		max = med;
	}

	return max;
}

int main() {

	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> work[i][0];
		cin >> work[i][1];
	}

	cout << go(N, 0, 0, -1) << "\n";


	return 0;
}