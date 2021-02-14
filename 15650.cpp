#include <iostream>
using namespace std;

bool check[9];
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
			if(check[i]){
				continue;
			}
			else {
				check[i] = true;
				result[index] = i;
				go(index + 1, i + 1, N, M);
				check[i] = false;
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	go(0, 1, N, M);

	return 0;
}