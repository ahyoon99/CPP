// 规过 1 : Top-Down
//#include <iostream>
//using namespace std;
//
//int d[11];
//
//int go(int n) {
//
//	if (n == 0) {
//		return 1;
//	}
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 2;
//	}
//	if (d[n] != 0) {
//		return d[n];
//	}
//
//	d[n] = go(n - 1) + go(n - 2) + go(n - 3);
//	return d[n];
//}
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	while (N--) {
//		int n;
//		cin >> n;
//		cout << go(n) << "\n";
//	}
//
//	return 0;
//}

// 规过 2 : Bottom-Up
#include <iostream>
using namespace std;

int d[12];

int main() {

	int N;
	cin >> N;

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	while (N--) {

		int n;
		cin >> n;

		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << "\n";
	}

	return 0;
}