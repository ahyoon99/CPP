// ¹æ¹ý 1 : Bottom-Up
#include <iostream>
#include <algorithm>
using namespace std;

long long price[3][100002];
long long d[100001][3];

int main() {

	int N;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> price[i][j];
			}
		}
		d[1][0] = 0;
		d[1][1] = price[1][1];
		d[1][2] = price[2][1];

		for (int i = 2; i <= n; i++) {
			d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + price[1][i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + price[2][i];
		}
		cout << max({ d[n][0], d[n][1], d[n][2] }) << "\n";

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				price[i][j] = 0;
				d[i][j] = 0;
			}
		}
	}

	return 0;
}