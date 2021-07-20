#include <iostream>
#include <string>
using namespace std;

int main() {

	int starting[3];
	int current[3];
	int result[3];


	string current_time;
	string starting_time;


	cin >> current_time;
	cin >> starting_time;

	for (int i = 0; i < 3; i++) {
		string com1 = "\0";
		string com2 = "\0";
		for (int j = 0; j < 2; j++) {
			com1 += current_time[3 * i + j];
			com2 += starting_time[3 * i + j];
		}

		current[i] = stoi(com1);
		starting[i] = stoi(com2);
	}

	for (int i = 2; i >= 0; i--) {
		if (i!=0 && starting[i] - current[i] < 0) {
			starting[i - 1]--;
			starting[i] += 60;
			result[i] = starting[i] - current[i];
		}
		else if (starting[i] - current[i] < 0) {
			result[i] = starting[i] - current[i] + 24;
		}
		else {
			result[i] = starting[i] - current[i];
		}
		
	}

	string str_result = "\0";
	for (int i = 0; i < 3; i++) {
		if (result[i] == 0) {
			str_result += "00";
		}
		else if (result[i] < 10) {
			str_result += "0";
			str_result += to_string(result[i]);
		}
		else {
			str_result += to_string(result[i]);
		}
		if (i != 2) {
			str_result += ":";
		}
	}

	cout << str_result;

	return 0;
}