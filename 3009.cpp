#include<iostream>
using namespace std;


int main() {

	int arr[3][2];

	int check_x[1001] = { 0, };
	int check_y[1001] = { 0, };

	for (int i = 0; i < 3; i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
		check_x[arr[i][0]]++;
		check_y[arr[i][1]]++;
	}


	for (int i = 0; i < 3; i++) {
		int a = arr[i][0];
		if (check_x[a] == 1) {
			cout << a << " ";
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		int a = arr[i][1];
		if (check_y[a] == 1) {
			cout << a << " ";
			break;
		}
	}


	return 0;
}