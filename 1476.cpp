 // 방법1
#include<iostream>
using namespace std;

int main() {

	int arr[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	int year = 0;
	int i = 0;
	while (true) {
		year = arr[0] + 15 * i;
		if ((year - arr[1]) % 28 == 0 && (year - arr[2]) % 19 == 0) {
			cout << year << "\n";
			return 0;
		}
		i++;
	}

	return 0;
}

// // 방법2
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	int E, S, M;
//	cin >> E >> S >> M;
//	int e = 1, s = 1, m = 1;
//	for (int i = 1;; i++) {
//		if (e == E && s == S && m == M) {
//			cout << i << "\n";
//			break;
//		}
//		e += 1;
//		s += 1;
//		m += 1;
//		if (e == 16) {
//			e = 1;
//		}
//		if (s == 29) {
//			s = 1;
//		}
//		if (m == 20) {
//			m = 1;
//		}
//	}
//	return 0;
//}

//// // 방법3
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	int e, s, m;
//	cin >> e >> s >> m;
//
//	// 어떤 수를 m으로 나누었을 때 나머지는 0~m-1이다.
//	e -= 1;
//	s -= 1;
//	m -= 1;
//
//	for (int i = 0;; i++) {
//		if (i % 15 == e && i % 28 == s && i % 19 == m) {
//			cout << i + 1 << "\n";
//			break;
//		}
//	}
//	return 0;
//}