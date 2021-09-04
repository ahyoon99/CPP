#include <iostream>
using namespace std;

int result[9];

void go(int index, int start, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = start; i <= N; i++) {
			result[index] = i;
			go(index + 1, i, N, M);
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	go(0, 1, N, M);

	return 0;
}