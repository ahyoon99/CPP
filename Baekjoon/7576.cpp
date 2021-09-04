#include <iostream>
#include <queue>
using namespace std;

int tomato[1001][1001];
int day[1001][1001];
int N, M;
int tot_tomato = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1) {
				q.push(make_pair(i,j));
				day[i][j] = 0;
				tot_tomato++;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= N - 1 && 0 <= ny && ny <= M - 1) {
				if (tomato[nx][ny] == 0 && day[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					day[nx][ny] = day[x][y] + 1;
					tot_tomato++;
				}
			}
		}
	}
}

int main() {

	cin >> M >> N;
	int zero_tomato = 0;
	int one_tomato = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 0) {
				zero_tomato++;
			}
			else if (tomato[i][j] == 1) {
				one_tomato++;
			}
		}
	}

	if (zero_tomato == 0) {
		cout << "0\n";
	}
	else {
		BFS(0, 0);

		if (tot_tomato == zero_tomato + one_tomato) {
			int tot_day = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (day[i][j] > tot_day) {
						tot_day = day[i][j];
					}
				}
			}

			cout << tot_day << "\n";
		}
		else {
			cout << "-1\n";
		}
		
	}

	return 0;
}