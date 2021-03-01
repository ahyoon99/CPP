// ¹æ¹ý 1 : Bottom-Up
#include <iostream>
using namespace std;

int d[1001];
int p[1001];

int main() {
	
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	d[1] = p[1];

	for (int j = 2; j <= N; j++) {
		int min = p[j];
		for (int i = j - 1; i >= 1; i--) {
			int temp = p[i] + d[j - i];

			if (min > temp) {
				min = temp;
			}
		}
		d[j] = min;
	}

	cout << d[N] << "\n";

	return 0;
}