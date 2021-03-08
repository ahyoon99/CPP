// 规过 1 : Top-Down
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int wine[10001];
//int d[10001][3];
//
//int go(int n, int i) {
//	if (n == 1) {
//		if (i == 0 || i == 2) {
//			return 0;
//		}
//		else if (i == 1) {
//			return wine[1];
//		}
//	}
//	if (d[n][i] != 0) {
//		return d[n][i];
//	}
//	if (i == 0) {
//		d[n][i] = max({ go(n - 1,0), go(n - 1,1), go(n - 1,2) });
//	}
//	else if (i == 1) {
//		d[n][i] = go(n - 1, 0) + wine[n];
//	}
//	else if (i == 2) {
//		d[n][i] = go(n - 1, 1) + wine[n];
//	}
//	return d[n][i];
//}
//
//int main() {
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> wine[i];
//	}
//
//	cout << max({ go(n,0),go(n,1) ,go(n,2) }) << "\n";
//
//	return 0;
//}

// 规过 2 : Bottom-Up
#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int d[10001][3];

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	d[1][0] = 0;
	d[1][1] = wine[1];
	d[1][2] = 0;

	for (int i = 2; i <= n; i++) {
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
		d[i][1] = d[i - 1][0] + wine[i];
		d[i][2] = d[i - 1][1] + wine[i];
	}

	cout << max({ d[n][0], d[n][1],d[n][2] }) << "\n";

	return 0;
}