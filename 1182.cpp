#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

vector<int> group;

void go(vector<int> a, int index, int sum, int result) {
	if (index == a.size()) {
		if (sum == result) {
			cnt += 1;
		}
		return;
	}
	group.push_back(a[index]);
	go(a, index + 1, sum + a[index], result);
	group.pop_back();
	go(a, index + 1, sum, result);
}

int main() {

	int N, S;
	cin >> N >> S;

	vector<int>num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	go(num, 0, 0, S);
	if (S == 0) {
		cnt -= 1;
	}

	cout << cnt << "\n";

	return 0;
}

//#include <iostream>
//using namespace std;
//
//int num[20];
//int cnt = 0;
//
//void go(int index, int sum, int result, int n) {
//	if (index == n && sum == result) {
//		cnt++;
//	}
//}
//
//
//int main() {
//
//	int N, S;
//	cin >> N >> S;
//
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//
//	go(0, 0, S, N);
//
//	return 0;
//}