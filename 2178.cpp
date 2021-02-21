#include <iostream>
#include <queue>
using namespace std;

int miro[102][102];
int count_miro[102][102];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;

void BFS(int x, int y,int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	count_miro[x][y] = cnt;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= N - 1 && 0 <= ny && ny <= M - 1) {
				if (count_miro[nx][ny] == -1 && miro[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					count_miro[nx][ny] = count_miro[x][y] + 1;
				}
			}
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j =0; j < M; j++) {
			if (a[j] == '0') {
				miro[i][j] = 0;
			}
			else if (a[j] == '1') {
				miro[i][j] = 1;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			count_miro[i][j] = -1;
		}
	}

	BFS(0, 0, 1);

	cout << count_miro[N-1][M-1] << "\n";

	return 0;
}