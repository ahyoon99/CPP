// ¹æ¹ý 1 : Bottom-Up
#include <iostream>
using namespace std;

int d[1001][10];

int main() {

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] + d[i - 1][k]) % 10007;
			}
		}
	}

	int tot = 0;
	for (int i = 0; i <= 9; i++) {
		tot = (tot + d[n][i]) % 10007;
	}
	cout << tot << "\n";

	return 0;
}