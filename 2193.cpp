// ¹æ¹ý 1 : Top-Down
#include <iostream>
using namespace std;

long long d[91][2];

long long go(int n, int i) {

	if (n == 0) {
		return 0;
	}
	if (n == 1){
		if (i == 0) {
			return 0;
		}
		else if (i == 1) {
			return 1;
		}
	}
	if (d[n][i] != 0) {
		return d[n][i];
	}
	if (i == 0) {
		d[n][i] = go(n - 1, 0) + go(n - 1, 1);
	}
	else if (i == 1) {
		d[n][i] = go(n - 2, 0) + go(n - 2, 1);
	}
	return d[n][i];
}

int main() {

	int n;
	cin >> n;

	long long tot = go(n, 0) + go(n, 1);
	cout << tot << "\n";

	return 0;
}