//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//
//	int first[9] = { 0, };
//	int sum = 0;
//
//	for (int i = 0; i < 9; i++) {
//		cin >> first[i];
//		sum += first[i];
//	}
//
//	sort(first, first + 9);
//
//	bool check = true;
//
//
//	for (int i = 0; i < 8; i++) {
//		for (int j = i + 1; j < 9; j++) {
//			int med = sum;
//			med = med - first[i] - first[j];
//			if (med == 100) {
//				for (int k = 0; k < 9; k++) {
//					if (k == i || k == j) {
//						continue;
//					}
//					else {
//						cout << first[k] << "\n";
//					}
//				}
//				check = false;
//			}
//			if (!check) {
//				break;
//			}
//		}
//		if (!check) {
//			break;
//		}
//	}
//
//
//
//	return 0;
//}

// 2¹øÂ°
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//
//	int first[9] = { 0, };
//	int sum = 0;
//
//	for (int i = 0; i < 9; i++) {
//		cin >> first[i];
//		sum += first[i];
//	}
//
//	sort(first, first + 9);
//
//	bool check = true;
//
//
//	for (int i = 0; i < 8; i++) {
//		for (int j = i + 1; j < 9; j++) {
//			int med = sum;
//			med = med - first[i] - first[j];
//			if (med == 100) {
//				for (int k = 0; k < 9; k++) {
//					if (k == i || k == j) {
//						continue;
//					}
//					else {
//						cout << first[k] << "\n";
//					}
//				}
//				return 0;
//			}
//		}
//	}
//
//
//
//	return 0;
//}
