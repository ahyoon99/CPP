// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//int d[1001];
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	d[1] = 1;
//	d[2] = 3;
//
//	for (int i = 3; i <= n; i++) {
//		d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
//	}
//
//	cout << d[n] << "\n";
//
//	return 0;
//
//}

// 规过 2 : Top-Down
#include <iostream>
using namespace std;

int d[1001];

int go(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	if (d[n] != 0) {
		return d[n];
	}
	d[n] = (go(n - 1) + (go(n - 2) * 2) % 10007) % 10007;
	return d[n];
}

int main() {

	int n;
	cin >> n;

	cout << go(n) << "\n";

	return 0;
}