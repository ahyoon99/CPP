#include <iostream>
#include <algorithm>
using namespace std;

int num[9];
int result[9];
bool check[10001];

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
			if (check[num[i]]) {
				continue;
			}
			else {
				check[num[i]] = true;
				result[index] = num[i];
				go(index + 1, N, M);
				check[num[i]] = false;
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N);

	go(0, N, M);

	return 0;
}