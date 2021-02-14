#include <iostream>
using namespace std;

bool check[9];
int result[9];

void go(int index, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == true) {
			continue;
		}
		else {
			check[i] = true;
			result[index] = i;
			go(index + 1, N, M);
			check[i] = false;
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	go(0, N, M);

	return 0;
}