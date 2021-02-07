#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;

void go(vector<int> a, int index, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}
	else if (a.size() == index) {
		return;
	}
	lotto.push_back(a[index]);
	go(a, index + 1, cnt+1);
	lotto.pop_back();
	go(a, index + 1, cnt);
}

int main() {

	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		else {

			vector<int> arr(k);

			for (int i = 0; i < k; i++) {
				cin >> arr[i];
			}
			go(arr, 0, 0);
			cout << "\n";
		}
	}


	return 0;
}