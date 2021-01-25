//#include<iostream>
//using namespace std;
//
//int GCD(int a, int b) {
//	while (b != 0) {
//		int r = a % b;
//		a = b;
//		b = r;
//	}
//	return a;
//}
//
//int main() {
//
//	int num;
//	cin >> num;
//	while (num--) {
//		int n;
//		cin >> n;
//		long long sum = 0;
//		int* number = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> number[i];
//		}
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = i + 1; j < n; j++) {
//				sum += GCD(number[i], number[j]);
//			}
//		}
//		cout << sum << endl;
//	}
//
//
//	return 0;
//}

#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {

		long long gcd_sum = 0;

		int num;
		cin >> num;
		
		int* arr = new int[num];

		for (int j = 0; j < num; j++) {
			cin >> arr[j];
		}

		for (int j = 0; j < num-1; j++) {
			for (int k = j + 1; k < num; k++) {
				gcd_sum += gcd(arr[j], arr[k]);
			}
		}
		cout << gcd_sum << "\n";
	}


	return 0;
}