//#include<iostream>
//using namespace std;
//
//int GCD(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		return GCD(b, a % b);
//	}
//}
//
//int LCM(int a, int b, int gcd) {
//	return a * b / gcd;
//}
//
//int main() {
//
//	int num;
//	cin >> num;
//	while (num--) {
//		int a, b;
//		cin >> a >> b;
//		int result = GCD(a, b);
//		cout << LCM(a, b, result) << endl;
//	}
//
//	return 0;
//
//}

// 2번째 시도
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << n1 * n2 / gcd(n1, n2) << "\n";
	}

	return 0;
}