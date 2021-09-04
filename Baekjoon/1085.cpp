#include<iostream>
using namespace std;

int main() {

	int x, y, w, h;
	int arr[4] = { 0, };

	cin >> x >> y >> w >> h;

	arr[0] = x;
	arr[1] = y;
	arr[2] = w - x;
	arr[3] = h - y;

	int min = 1000;
	for (int i = 0; i < 4; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << min << "\n";


	return 0;
}