#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, S;
	cin >> N >> S;

	vector<int> num(N);
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int cnt = 0;

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sum += num[j];
			}
		}
		if (sum == S) {
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}