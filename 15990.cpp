// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//long long d[100001][4];
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	d[1][1] = 1;
//	d[1][2] = 0;
//	d[1][3] = 0;
//
//	d[2][1] = 0;
//	d[2][2] = 1;
//	d[2][3] = 0;
//
//	d[3][1] = 1;
//	d[3][2] = 1;
//	d[3][3] = 1;
//
//	while (N--) {
//		int n;
//		cin >> n;
//
//		for (int i = 4; i <= 100000; i++) {
//
//			d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
//			d[i][2] = d[i - 2][1] + d[i - 2][3] % 1000000009;
//			d[i][3] = d[i - 3][1] + d[i - 3][2] % 1000000009;
//
//		}
//
//		cout << (((d[n][1] + d[n][2]) % 1000000009) + d[n][3]) % 1000000009 << "\n";
//
//	}
//
//	return 0;
//}

// 规过 2 : Top-Down
#include <iostream>
using namespace std;

long long d[100001][4];

int go(int n, int i) {
	if (n == 1) {
		if (i == 1) {
			return 1;
		}
		else if (i == 2 || i == 3) {
			return 0;
		}
	}
	else if (n == 2) {
		if (i == 1 || i == 3) {
			return 0;
		}
		else if (i == 2) {
			return 1;
		}
	}
	else if (n == 3) {
		return 1;
	}
	if (d[n][i] != 0) {
		return d[n][i];
	}
	if (i == 1) {
		d[n][i] = (go(n - 1, 2) + go(n - 1, 3)) % 1000000009;
	}
	else if (i == 2) {
		d[n][i] = (go(n - 2, 1) + go(n - 2, 3)) % 1000000009;
	}
	else if (i == 3) {
		d[n][i] = (go(n - 3, 1) + go(n - 3, 2)) % 1000000009;
	}
	return d[n][i];
}

int main() {

	int N;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;
		
		int tot = 0;

		for (int i = 1; i <= 3; i++) {
			tot = (tot + go(n, i)) % 1000000009;
		}
		cout << tot << "\n";
	}
	return 0;
}