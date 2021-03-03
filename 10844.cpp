// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//long long d[101][10];
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 9; j++) {
//			if (j == 0) {
//				d[i][0] = d[i - 1][1];
//			}
//			else if (j == 9) {
//				d[i][9] = d[i - 1][8];
//			}
//			else {
//				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
//			}
//		}
//	}
//
//	long long tot = 0;
//
//	for (int i = 0; i <= 9; i++) {
//		tot = (tot + d[n][i]) % 1000000000;
//	}
//
//	cout << tot << "\n";
//
//	return 0;
//}

// 规过 2 : Top-Down
#include <iostream>
using namespace std;

long long d[101][10];

int go(int n, int i) {

	if (n == 1) {
		if (i == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (d[n][i] != 0) {
		return d[n][i];
	}

	if (i == 9) {
		d[n][9] = go(n - 1, 8);
	}
	else if (i == 0) {
		d[n][0] = go(n - 1, 1);
	}
	else {
		d[n][i] = (go(n - 1, i - 1) + go(n - 1, i + 1)) % 1000000000;
	}

	return d[n][i];
}

int main() {

	int n;
	cin >> n;

	long long tot = 0;

	for (int i = 0; i <= 9; i++) {
		tot = (tot + go(n,i)) % 1000000000;
	}

	cout << tot << "\n";

	return 0;
}