#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	//int a, d, k;
	int a, int_d, int_k;
	cin >> a >> int_d >> int_k;
	double arr[10000];

	double d = (double)int_d / 100;
	double k = (double)int_k / 100;

	arr[0] = d;
	int cnt = 1;
	while (true) {
		d = d + d * k;
		if (d >= 1) {
			arr[cnt] = 1;
			cnt++;
			break;
		}
		arr[cnt] = d;
		cnt++;
	}

	double pro = 0;
	
	for (int i = 0; i < cnt; i++) {
		double med = 1;
		int min = a * (i+1);
		for (int j = 0; j < i; j++) {
			med *= (double(1) - arr[j]);
		}
		med *= arr[i];
		pro += med * min;
	}

	cout << fixed;
	cout.precision(7);
	cout << pro << "\n";


	return 0;
}