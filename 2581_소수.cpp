#include<iostream>
using namespace std;

#define MAX 10001


bool prime[MAX] = { false, };
int sum = 0;
int first_prime = -1;
bool check = false;

void isPrime(int a, int b) {
	prime[1] = true;
	for (int i = a; i <= b; i++) {
		for (int k = 2; k * k <= i; k++) {
			if (i % k == 0) {
				prime[i] = true;
				break;
			}
		}
		if (prime[i] == false) {
			check = true;
			if (sum == 0) {
				first_prime = i;
			}
			sum += i;
		}
	}
}

int main() {

	int M, N;
	cin >> M >> N;
	isPrime(M, N);
	if (check) {
		printf("%d\n", sum);
		printf("%d\n", first_prime);
	}
	else {
		printf("%d\n", -1);
	}

	return 0;
}