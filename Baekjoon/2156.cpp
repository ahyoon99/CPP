// ��� 1 : Top-Down
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

// ��� 2 : Bottom-Up
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int wine[10001];
//int d[10001][3];
//
//int main() {
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> wine[i];
//	}
//
//	d[1][0] = 0;
//	d[1][1] = wine[1];
//	d[1][2] = 0;
//
//	for (int i = 2; i <= n; i++) {
//		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
//		d[i][1] = d[i - 1][0] + wine[i];
//		d[i][2] = d[i - 1][1] + wine[i];
//	}
//
//	cout << max({ d[n][0], d[n][1],d[n][2] }) << "\n";
//
//	return 0;
//}

// ��� 3 : 1���� �迭 ��� , Bottom-Up
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int wine[10001];
//int d[10001];
//
//int main() {
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> wine[i];
//	}
//
//	d[1] = wine[1];
//	d[2] = wine[1] + wine[2];
//
//	for (int i = 3; i <= n; i++) {
//		d[i] = d[i - 1];
//		if (d[i] < d[i - 2] + wine[i]) {
//			d[i] = d[i - 2] + wine[i];
//		}
//		if (d[i] < d[i - 3] + wine[i] + wine[i - 1]) {
//			d[i] = d[i - 3] + wine[i] + wine[i - 1];
//		}
//	}
//
//	cout << d[n] << "\n";
//
//	return 0;
//}

// ��� 4 : 1���� �迭 ��� , Top-Down
#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int d[10001];

int go(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return wine[1];
	}
	if (n == 2) {
		return wine[1] + wine[2];
	}
	if (d[n] != 0) {
		return d[n];
	}

	d[n] = go(n - 1);
	if (d[n] < go(n - 2) + wine[n]) {
		d[n] = go(n - 2) + wine[n];
	}
	if (d[n] < go(n - 3) + wine[n - 1] + wine[n]) {
		d[n] = go(n - 3) + wine[n - 1] + wine[n];
	}

	return d[n];
}

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	cout << go(n) << "\n";

	return 0;
}