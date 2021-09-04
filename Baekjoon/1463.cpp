// 规过 1 : Bottom-Up
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int d[1000000];
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	d[1] = 0;
//
//	for (int i = 2; i <= N; i++) {
//		d[i] = d[i - 1] + 1;
//
//		if (i % 3 == 0) {
//			if (d[i] > d[i / 3] + 1) {
//				d[i] = d[i / 3] + 1;
//			}
//		}
//		if (i % 2 == 0) {
//			if (d[i] > d[i / 2] + 1) {
//				d[i] = d[i / 2] + 1;
//			}
//		}
//	}
//	
//	cout << d[N] << "\n";
//
//	return 0;
//}

// 规过 1 : Top-Down
#include <iostream>
using namespace std;

int d[1000001];

int go(int N) {
	if (N == 1) {
		d[1] = 0;
		return 0;
	}

	if (d[N] != 0) {
		return d[N];
	}

	if (d[N] == 0) {

		d[N] = go(N - 1) + 1;

		if (N % 2 == 0 && d[N] > go(N / 2) + 1) {
			d[N] = go(N / 2) + 1;
		}

		if (N % 3 == 0 && d[N] > go(N / 3) + 1) {
			d[N] = go(N / 3) + 1;
		}
		return d[N];
	}
}

int main() {

	int N;
	cin >> N;

	cout << go(N) << "\n";

	return 0;
}