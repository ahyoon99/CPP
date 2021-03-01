// ¹æ¹ý 1 : Bottom-Up
#include <iostream>
using namespace std;

int d[1000001];

int  main() {

	int N;
	cin >> N;

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	while (N--) {
		int n;
		cin >> n;
		
		for (int i = 3; i <= n; i++) {
			d[i] = (((d[i - 1] + d[i - 2]) % 1000000009) + d[i - 3]) % 1000000009;
		}

		cout << d[n] << "\n";

	}

	return 0;
}