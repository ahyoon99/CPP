// 规过 1 : Bottom-Up
//#include <iostream>
//using namespace std;
//
//int d[1000001];
//
//int  main() {
//
//	int N;
//	cin >> N;
//
//	d[0] = 1;
//	d[1] = 1;
//	d[2] = 2;
//
//	while (N--) {
//		int n;
//		cin >> n;
//		
//		for (int i = 3; i <= n; i++) {
//			d[i] = (((d[i - 1] + d[i - 2]) % 1000000009) + d[i - 3]) % 1000000009;
//		}
//
//		cout << d[n] << "\n";
//
//	}
//
//	return 0;
//}


// 规过 2 : Top-Down
#include <iostream>
using namespace std;

int d[1000001];

int go(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (d[n] != 0) {
		return d[n];
	}
	d[n] = (((go(n - 1) + go(n - 2)) % 1000000009) + go(n - 3)) % 1000000009;
	return d[n];
}

int main() {

	int N;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;

		cout << go(n) << "\n";
	}

	return 0;
}