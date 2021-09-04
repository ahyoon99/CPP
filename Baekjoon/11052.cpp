// 规过 1 : Top-Down
//#include <iostream>
//using namespace std;
//
//int d[1001];
//int p[10000];
//
//int go(int n) {
//	if (n == 1) {
//		return p[1];
//	}
//	if (d[n] != 0) {
//		return d[n];
//	}
//
//	int max = p[n];
//	for (int j = n-1; j >= 1; j--) {
//		int temp = p[j] + go(n - j);
//		if (max < temp) {
//			max = temp;
//		}
//	}
//	d[n] = max;
//
//	return d[n];
//}
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		cin >> p[i];
//	}
//
//	cout << go(N) << "\n";
//
//	return 0;
//}


// 规过 2 : Bottom-Up
#include <iostream>
using namespace std;

int p[1001];
int d[1001];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	d[1] = p[1];

	for (int i = 2; i <= n; i++) {
		int max = p[i];
		for (int j = 1; j < i; j++) {
			if (max < p[j] + d[i - j]) {
				max = p[j] + d[i - j];
			}
		}
		d[i] = max;
	}

	cout << d[n] << "\n";

	return 0;
}