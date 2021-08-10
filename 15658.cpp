#include <iostream>
using namespace std;

int num[12];
int cal[4];

int min = 10000000000;
int max = -10000000000;

void go(int num_size, int idx, int result, int cal1, int cal2, int cal3, int cal4) {
	if (idx > num_size - 1) {
		return;
	}
	else if (idx == num_size - 1) {
		if (result < ::min) {
			::min = result;
		}
		if (result > ::max) {
			::max = result;
		}
		return;
	}

	if (cal1 != 0) {
		go(num_size, idx + 1, result + num[idx + 1], cal1 - 1, cal2, cal3, cal4);
	}
	if (cal2 != 0) {
		go(num_size, idx + 1, result - num[idx + 1], cal1, cal2 - 1, cal3, cal4);
	}
	if (cal3 != 0) {
		go(num_size, idx + 1, result * num[idx + 1], cal1, cal2, cal3 - 1, cal4);
	}
	if (cal4 != 0) {
		go(num_size, idx + 1, result / num[idx + 1], cal1, cal2, cal3, cal4 - 1);
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}

	go(N, 0, num[0], cal[0], cal[1], cal[2], cal[3]);
	cout << ::max << "\n" << ::min << "\n";

	return 0;
}