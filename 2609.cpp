//#include<iostream>
//using namespace std;
//
//int GCD(int a, int b) {
//	while (b!=0)
//	{
//		int r = a % b;
//		a = b;
//		b = r;
//	}
//	return a;
//}
//
//int LCM(int a, int b, int gcd) {
//	return a * b / gcd;
//}
//
//int main() {
//
//	int a, b;
//	cin >> a >> b;
//
//	int gcd = GCD(a, b);
//	int lcm = LCM(a, b, gcd);
//
//	cout << gcd << "\n";
//	cout << lcm << "\n";
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int min(int a, int b) {
//    if (a > b) {
//        return b;
//    }
//    else {
//        return a;
//    }
//}
//
//int GCD(int a, int b) {
//    int gcd = 1;
//    for (int i = 2; i <= min(a, b); i++) {
//        if (a % i == 0 && b % i == 0) {
//            gcd = i;
//        }
//    }
//    return gcd;
//}
//
//int LCM(int a, int b, int gcd) {
//    return a * b / gcd;
//}
//
//int main() {
//
//    int a, b;
//    cin >> a >> b;
//
//    int gcd = GCD(a, b);
//    int lcm = LCM(a, b, gcd);
//
//    cout << gcd << "\n";
//    cout << lcm << "\n";
//
//    return 0;
//}


// 3번째시도
#include <iostream>
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

	int n1, n2;

	cin >> n1 >> n2;

	cout << gcd(n1, n2) << "\n";
	cout << n1 * n2 / gcd(n1, n2) << "\n";

	return 0;
}