#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

bool miro[1001][1001];
int dist[1001][1001][2];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void BFS(int N, int M) {

	queue <tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));
	
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= N - 1 && 0 <= ny && ny <= M - 1) {
				if (miro[nx][ny] == false && dist[nx][ny][z] == 0) {
					dist[nx][ny][z] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (miro[nx][ny] == true && dist[nx][ny][z+1] == 0 && z == 0) {
					dist[nx][ny][z + 1] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}

	if (dist[N - 1][M - 1][0] != 0 && dist[N - 1][M - 1][1] != 0) {
		cout << min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]) << "\n";
	}
	else if (dist[N - 1][M - 1][0] != 0) {
		cout << dist[N - 1][M - 1][0] << "\n";
	}
	else if (dist[N - 1][M - 1][1] != 0) {
		cout << dist[N - 1][M - 1][1] << "\n";
	}
	else {
		cout << "-1\n";
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			if (a[j] == '0') {
				miro[i][j] = false;
			}
			else if (a[j] == '1') {
				miro[i][j] = true;
			}
		}
	}

	BFS(N, M);

	return 0;
}