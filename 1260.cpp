#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool check[1001];
vector<int> num[1001];

void DFS(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < num[x].size(); i++) {
		int y = num[x][i];
		if (check[y] == false) {
			DFS(y);
		}
	}
}

void BFS(int x) {
	queue <int> q;

	check[x] = true;
	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < num[x].size(); i++) {
			int y = num[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}

}

int main() {

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		num[a].push_back(b);
		num[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		sort(num[i].begin(), num[i].end());
	}

	DFS(V);
	cout << "\n";

	for (int i = 0; i <= N; i++) {
		check[i] = false;
	}

	BFS(V);

	return 0;
}