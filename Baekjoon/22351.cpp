#include <iostream>
#include <string>
using namespace std;


int main() {


	string com;
	cin >> com;
	int ans1, ans2;

	for (int i = 1; i <= com.length(); i++) {
		int cnt = 0;
		string str_num1 = "\0";
		int int_num1 = 0;

		for (int j = 0; j < i; j++) {
			str_num1 += com[j];
			cnt++;
			ans1 = stoi(str_num1);
		}

		string str_num2 = to_string(stoi(str_num1) - 1);
		for (int j = 0; j <= com.length(); j += str_num2.length()) {
			int_num1 = stoi(str_num2) + 1;
			str_num2 = to_string(int_num1);
			if (str_num2.length() == 1) {
				if (str_num2[0] == com[j]) {
					cnt++;
				}
				else {
					break;
				}
			}
			else if (str_num2.length() == 2) {
				if (str_num2[0] == com[j] && str_num2[1] == com[j + 1]) {
					cnt += 2;
				}
				else {
					break;
				}
			}
			else if (str_num2.length() == 3) {
				if (str_num2[0] == com[j] && str_num2[1] == com[j + 1] && str_num2[2] == com[j + 2]) {
					cnt += 3;
				}
				else {
					break;
				}
			}
			if (j + str_num2.length() == com.length()) {
				ans2 = stoi(str_num2);
				cout << ans1 << " " << ans2 << "\n";
				return 0;
			}

		}

	}


	return 0;
}