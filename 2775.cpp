#include<iostream>
using namespace std;
#define MAX 15

int main() {

	int arr[MAX][MAX];

	int num;
	cin >> num;
	while (num--) {
		int k, n;
		cin >> k >> n;
		for (int i = 1; i <= n; i++) {
			arr[0][i] = i;
		}
		for (int i = 0; i <= k; i++) {
			arr[i][0] = 0;
		}
		for (int i = 0; i < k; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i + 1][j] = arr[i + 1][j - 1] + arr[i][j];
			}
		}
		cout << arr[k][n] << "\n";
	}

	return 0;
}