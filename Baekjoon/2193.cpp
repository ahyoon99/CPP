// ��� 1 : Top-Down
//#include <iostream>
//using namespace std;
//
//long long d[91][2];
//
//long long go(int n, int i) {
//
//	if (n == 0) {
//		return 0;
//	}
//	if (n == 1){
//		if (i == 0) {
//			return 0;
//		}
//		else if (i == 1) {
//			return 1;
//		}
//	}
//	if (d[n][i] != 0) {
//		return d[n][i];
//	}
//	if (i == 0) {
//		d[n][i] = go(n - 1, 0) + go(n - 1, 1);
//	}
//	else if (i == 1) {
//		d[n][i] = go(n - 2, 0) + go(n - 2, 1);
//	}
//	return d[n][i];
//}
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	long long tot = go(n, 0) + go(n, 1);
//	cout << tot << "\n";
//
//	return 0;
//}

// ��� 2 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//long long d[91][2];
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	d[1][0] = 0;
//	d[1][1] = 1;
//	d[2][0] = 1;
//	d[2][1] = 0;
//
//	for (int i = 3; i <= n; i++) {
//		d[i][0] = d[i - 1][0] + d[i - 1][1];
//		d[i][1] = d[i - 2][0] + d[i - 2][1];
//	}
//
//	cout << d[n][0] + d[n][1] << "\n";
//
//	return 0;
//}

// ��� 3 : 1���� �迭 ��� , Bottom-Up
//#include <iostream>
//using namespace std;
//
//long long d[91];
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	d[1] = 1;
//	d[2] = 1;
//
//	for (int i = 3; i <= n; i++) {
//		d[i] = d[i - 1] + d[i - 2];
//	}
//
//	cout << d[n] << "\n";
//
//	return 0;
//}

// ��� 4 : 1���� �迭 ��� , Top-Down
#include <iostream>
using namespace std;

long long d[91];

long long go(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (d[n] != 0) {
		return d[n];
	}
	d[n] = go(n - 1) + go(n - 2);
	return d[n];
}

int main() {

	int n;
	cin >> n;
	cout << go(n) << "\n";

	return 0;
}