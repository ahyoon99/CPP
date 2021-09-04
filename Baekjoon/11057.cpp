// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//int d[1001][10];
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 9; j++) {
//			for (int k = 0; k <= j; k++) {
//				d[i][j] = (d[i][j] + d[i - 1][k]) % 10007;
//			}
//		}
//	}
//
//	int tot = 0;
//	for (int i = 0; i <= 9; i++) {
//		tot = (tot + d[n][i]) % 10007;
//	}
//	cout << tot << "\n";
//
//	return 0;
//}

// 规过 2 : Top-Down
#include <iostream>
using namespace std;

int d[1001][10];

int go(int n, int i) {
	if (n == 1) {
		return 1;
	}
	if (d[n][i] != 0) {
		return d[n][i];
	}

	for (int x = 0; x <= i; x++) {
		d[n][i] = (d[n][i] + go(n - 1, x)) % 10007;
	}
	
	return d[n][i];
}

int main() {

	int n;
	cin >> n;

	int tot = 0;
	for (int i = 0; i < 10; i++) {
		tot = (tot + go(n, i)) % 10007;
	}
	cout << tot << "\n";

	return 0;
}