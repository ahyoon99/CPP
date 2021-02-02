//// 10중 포문 사용 || 재귀함수 사용
//#include<iostream>
//using namespace std;
//
//int add(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	else if (n == 2) {
//		return 2;
//	}
//	else {
//
//	}
//}
//
//int main() {
//
//	int N;
//	cin >> N;
//	while (N--) {
//		int count = 0;
//		int number;
//		cin >> number;
//
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		int ans = 0;
		for (int l1 = 1; l1 <= 3; l1++) {
			if (l1 == n) {
				ans++;
			}
			for (int l2 = 1; l2 <= 3; l2++) {
				if (l1 + l2 == n) {
					ans++;
				}
				for (int l3 = 1; l3 <= 3; l3++) {
					if (l1 + l2 + l3 == n) {
						ans++;
					}
					for (int l4 = 1; l4 <= 3; l4++) {
						if (l1 + l2 + l3 +l4== n) {
							ans++;
						}
						for (int l5 = 1; l5 <= 3; l5++) {
							if (l1 + l2 + l3 + l4 + l5 == n) {
								ans++;
							}
							for (int l6 = 1; l6 <= 3; l6++) {
								if (l1 + l2 + l3 + l4 + l5 + l6 == n) {
									ans++;
								}
								for (int l7 = 1; l7 <= 3; l7++) {
									if (l1 + l2 + l3 + l4 + l5 + l6 + l7 == n) {
										ans++;
									}
									for (int l8 = 1; l8 <= 3; l8++) {
										if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == n) {
											ans++;
										}
										for (int l9 = 1; l9 <= 3; l9++) {
											if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == n) {
												ans++;
											}
											for (int l10 = 1; l10 <= 3; l10++) {
												if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 == n) {
													ans++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans << "\n";

	}

	
	return 0;
}