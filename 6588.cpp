#include<iostream>
using namespace std;

#define MAX 1000000
bool prime[MAX+1] = { false };

void isPrime(int a) {
	prime[1] = true;
	for (int i = 2; i <= a; i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			prime[j] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	isPrime(1000000);
	while (true) {

		int a;
		cin >> a;
		if (a == 0) {
			break;
		}
		else {
			if (!prime[a - 2]) {
				cout << a << " = " << 2 << " + " << a - 2 << "\n";
			}
			else {
				bool check = false;
				for (int i = 3; i <= a-3; i+=2) {
					if (!prime[i] && !prime[a - i]) {
						cout << a << " = " << i << " + " << a - i << "\n";
						check = true;
						break;
					}
				}
				if (!check) {
					cout << "Goldbach's conjecture is wrong.\n";
				}
			}
			
		}
	}

	return 0;
}