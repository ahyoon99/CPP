#include <iostream>
#include <queue>
using namespace std;

int dist[1001][1001];

void BFS(int S) {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	dist[1][0] = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (dist[a][a] == -1) {
			q.push(make_pair(a, a));
			dist[a][a] = dist[a][b] + 1;
		}

		if (a + b <= S) {
			if (dist[a + b][b] == -1) {
				q.push(make_pair(a + b, b));
				dist[a + b][b] = dist[a][b] + 1;
			}
		}
		
		if (a - 1 >= 0) {
			if (dist[a - 1][b] == -1) {
				q.push(make_pair(a - 1, b));
				dist[a - 1][b] = dist[a][b] + 1;
			}
		}
	}
}

int main() {

	int S;
	cin >> S;

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dist[i][j] = -1;
		}
	}

	BFS(S);

	int min_cnt = 1001;
	for (int i = 0; i < 1001; i++) {
		if (dist[S][i] != -1) {
			if (dist[S][i] < min_cnt) {
				min_cnt = dist[S][i];
			}
		}
	}

	cout << min_cnt << "\n";

	return 0;
}