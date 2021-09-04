//#include<iostream>
//using namespace std;
//
//bool isPrime(int n) {
//	if (n < 2) {
//		return false;
//	}
//	else {
//		for (int i = 2; i <= n / 2; i++) {
//			if (n % i == 0) {
//				return false;
//			}
//		}
//		return true;
//	}
//}
//
//int main() {
//
//	int num;
//	cin >> num;
//	int count = 0;
//	for (int i = 0; i < num; i++) {
//		int input;
//		cin >> input;
//		if (isPrime(input)) {
//			count++;
//		}
//	}
//	cout << count << endl;
//
//	return 0;
//}


// 2¹øÂ°
#include <iostream>
using namespace std;

bool isPrime(int a) {
	if (a < 2) {
		return false;
	}
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int N;
	cin >> N;
	
	int prime_count = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (isPrime(num)) {
			prime_count++;
		}
	}

	cout << prime_count << "\n";

	return 0;
}