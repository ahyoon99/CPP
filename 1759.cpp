#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool check(string pwd) {
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < pwd.length(); i++) {
		if (pwd[i] == 'a' || pwd[i] == 'e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	if (mo>=1 && ja>=2) {
		return true;
	}
	else {
		return false;
	}
}

void go(int n,vector<char> &alp, string pwd, int i) {

	if (pwd.length() == n) {
		if (check(pwd)) {
			cout << pwd << "\n";
		}
		return;
	}

	if (i >= alp.size()) {
		return;
	}

	go(n, alp, pwd + alp[i], i + 1);
	go(n, alp, pwd, i + 1);
	
}

int main() {

	int L, C;
	cin >> L >> C;

	vector<char> alp(C);

	for (int i = 0; i < C; i++) {
		cin >> alp[i];
	}

	sort(alp.begin(), alp.end());

	go(L, alp, "", 0);

	return 0;
}