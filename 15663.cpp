//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int num[9];
//int result[9];
//int pre[9] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
//bool check[10001];
//
//void go(int index, int N, int M) {
//	if (index == M) {
//
//		bool ch = false;
//		for (int i = 0; i < M; i++) {
//			if (pre[i] != result[i]) {
//				ch = true;
//				break;
//			}
//		}
//
//		if (ch) {
//			for (int i = 0; i < M; i++) {
//				cout << result[i] << " ";
//			}
//			cout << "\n";
//		}
//
//		for (int i= 0; i < M; i++) {
//			pre[i] = result[i];
//		}
//		return;
//	}
//	else {
//		for (int i = 0; i < N; i++) {
//			if (check[num[i]]) {
//				continue;
//			}
//			else {
//				check[num[i]] = true;
//				result[index] = num[i];
//				go(index + 1, N, M);
//				check[num[i]] = false;
//			}
//		}
//	}
//}
//
//int main() {
//
//	int N, M;
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//
//	sort(num, num + N);
//
//	go(0, N, M);
//
//	return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;

int origin[9];
int num[9];
int result[9];
int check_cnt[9] = { 1,1,1,1,1,1,1,1,1 };

void go(int index, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check_cnt[i] > 0) {
				check_cnt[i]--;
				result[index] = num[i];
				go(index + 1, N, M);
				check_cnt[i]++;
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> origin[i];
	}

	sort(origin, origin + N);

	num[0] = origin[0];

	int idx = 0;
	int cnt = 0;

	for (int i = 1; i < N; i++) {
		if (origin[i-1] == origin[i]) {
			check_cnt[idx]++;
			cnt++;
		}
		else {
			idx++;
			num[idx] = origin[i];
		}
	}

	go(0, N-cnt, M);

	return 0;
}