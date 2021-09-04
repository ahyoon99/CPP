#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check[20001];
vector<int> num[20001];

void DFS(int x, int color) {
	check[x] = color;
	//cout << x << " ";
	for (int i = 0; i < num[x].size(); i++) {
		int y = num[x][i];
		if (check[y] == 0) {
			DFS(y, 3 - color);
		}
	}
}

int main() {

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int V, E;
		cin >> V >> E;

		for (int j = 0; j < E; j++) {
			int a, b;
			cin >> a >> b;
			num[a].push_back(b);
			num[b].push_back(a);
		}

		for (int j = 1; j <= V; j++) {
			sort(num[j].begin(), num[j].end());
		}

		for (int j = 1; j <= V; j++) {
			if (check[j] == 0) {
				DFS(j, 1);
			}
		}

		bool color_check = true;
		for (int j = 1; j <= V; j++) {
			for (int k = 0; k < num[j].size(); k++) {
				int y = num[j][k];
				if (check[y] != 3 - check[j]) {
					color_check = false;
					break;
				}
			}
		}
		if (color_check) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		for (int i = 1; i <= V; i++) {
			num[i].clear();
			check[i] = 0;
		}
	}
	 
	return 0;
}