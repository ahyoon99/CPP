#include <iostream>
using namespace std;

int main() {
	
	int prev_statement1[3];
	int prev_statement2[3];

	int statement1[3];
	int statement2[3];
	int result[3];

	int x, y;

	for (int i = 0; i < 3; i++) {
		cin >> prev_statement1[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> prev_statement2[i];
	}

	for (int i = 0; i < 3; i++) {
		statement1[i] = prev_statement1[i] * prev_statement2[0] * -1;
		statement2[i] = prev_statement2[i] * prev_statement1[0];
	}
	for (int i = 0; i < 3; i++) {
		result[i] = statement1[i] + statement2[i];
	}

	y = result[2] / result[1];
	x = (prev_statement2[2] - prev_statement2[1] * y) / prev_statement2[0];

	cout << x <<" "<< y << "\n";

	return 0;
}