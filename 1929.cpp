////아래 방법 둘다 시간초과 안뜬다. cout만 안쓰면...
//
//#include<iostream>
//using namespace std;
//
//#define MAX 1000000
//
//bool prime[MAX] = { false, };
//
//void isPrime(int a, int b) {
//	prime[1] = true;
//	for (int i = a; i <= b; i++) {
//		for (int k = 2; k * k <= i; k++) {
//			if (i % k == 0) {
//				prime[i] = true;
//				break;
//			}
//		}
//		if (prime[i] == false) {
//			//cout << i << endl;
//			printf("%d\n", i);
//		}
//	}
//}
//
//int main() {
//
//	int M, N;
//	cin >> M >> N;
//	isPrime(M,N);
//	
//	return 0;
//}

// 2번째
//#include<iostream>
//using namespace std;
//
//#define MAX 1000000
//
//bool prime[MAX+1] = { false, };
//
//void isPrime(int a) {
//	prime[1] = true;
//	for (int i = 2; i*i <= a; i++) {
//		for (int k = i * 2; k <= a; k+=i) {
//			prime[k] = true;
//		}
//	}
//}
//
//int main() {
//
//	int M, N;
//	cin >> M >> N;
//	isPrime(N);
//	for (int i = M; i <= N; i++) {
//		if (prime[i] == false) {
//			//cout << i << endl;
//			printf("%d\n", i);	//cout은 시간초과...printf로 쓰기.
//		}
//	}
//	
//	return 0;
//}
