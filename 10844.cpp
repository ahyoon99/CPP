// ¹æ¹ý 1 : Bottom-Up
#include <iostream>
using namespace std;

long long d[101][10];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				d[i][0] = d[i - 1][1];
			}
			else if (j == 9) {
				d[i][9] = d[i - 1][8];
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long tot = 0;

	for (int i = 0; i <= 9; i++) {
		tot = (tot + d[n][i]) % 1000000000;
	}

	cout << tot << "\n";

	return 0;
}