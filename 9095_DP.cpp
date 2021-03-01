// ¹æ¹ý 1 : Top-Down
#include <iostream>
using namespace std;

int d[11];

int go(int n) {

	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (d[n] != 0) {
		return d[n];
	}

	d[n] = go(n - 1) + go(n - 2) + go(n - 3);
	return d[n];
}

int main() {

	int N;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;
		cout << go(n) << "\n";
	}

	return 0;
}