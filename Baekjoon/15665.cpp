#include <iostream>
#include <algorithm>
using namespace std;

int origin[9];
int num[9];
int result[9];

void go(int index, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			result[index] = num[i];
			go(index + 1, N, M);
		}
	}

}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> origin[i];
	}

	sort(origin, origin + N);

	num[0] = origin[0];
	int idx = 0;
	int cnt = 0;

	for (int i = 1; i < N; i++) {
		if (origin[i - 1] == origin[i]) {
			cnt++;
		}
		else {
			idx++;
			num[idx] = origin[i];
		}
	}

	go(0, N-cnt, M);

	return 0;
}