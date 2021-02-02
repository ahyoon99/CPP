#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100001

int main() {

	int n;
	cin >> n;
	int num[MAX] = { 0, };

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	cout << num[0] * num[n-1] << "\n";

	return 0;
}