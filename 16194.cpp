// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//int d[1001];
//int p[1001];
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
//	d[1] = p[1];
//
//	for (int j = 2; j <= N; j++) {
//		int min = p[j];
//		for (int i = j - 1; i >= 1; i--) {
//			int temp = p[i] + d[j - i];
//
//			if (min > temp) {
//				min = temp;
//			}
//		}
//		d[j] = min;
//	}
//
//	cout << d[N] << "\n";
//
//	return 0;
//}

// 规过 1 : Top-Down
#include <iostream>
using namespace std;

int p[1001];
int d[1001];

int go(int n) {
	if (n == 1) {
		return p[1];
	}
	if (d[n] != 0) {
		return d[n];
	}
	
	int min = p[n];
	for (int j = 1; j < n; j++) {
		if (min > p[j] + go(n - j)) {
			min = p[j] + go(n - j);
		}
	}
	d[n] = min;

	return d[n];

}

int main() {

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	cout << go(n) << "\n";

	return 0;
}