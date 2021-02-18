#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> num[1001];
bool check[1001];

void DFS(int x) {
	check[x] = true;
	//cout << x << " ";
	for (int i = 0; i < num[x].size(); i++) {
		int y = num[x][i];
		if (check[y] == false) {
			DFS(y);
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		num[a].push_back(b);
		num[b].push_back(a);
	}

	for (int i = 0; i <= N; i++) {
		sort(num[i].begin(), num[i].end());
	}

	int tot_cnt = 0;

	while (true) {
		int now_idx;
		bool is_check = true;
		for (int i = 1; i <= N; i++) {
			if (check[i] == false) {
				now_idx = i;
				is_check = false;
				break;
			}
		}
		if (!is_check) {
			DFS(now_idx);
			tot_cnt++;
		}
		else {
			break;
		}
	}

	cout << tot_cnt << "\n";

	return 0;
}