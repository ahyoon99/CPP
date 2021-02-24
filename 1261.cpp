#include <iostream>
#include <deque>
using namespace std;

bool miro[101][101];	// miro 입력
bool check[101][101];	// 방문하였는지 여부 체크
int broke[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void BFS(int N, int M) {

	deque <pair<int, int>> q;

	q.push_back(make_pair(0, 0));
	check[0][0] = true;
	broke[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= M - 1 && 0 <= ny && ny <= N - 1) {
				if (check[nx][ny] == false) {
					if (miro[nx][ny] == false) {
						q.push_front(make_pair(nx, ny));
						check[nx][ny] = true;
						broke[nx][ny] = broke[x][y];
					}
					else if (miro[nx][ny] == true) {
						q.push_back(make_pair(nx, ny));
						check[nx][ny] = true;
						broke[nx][ny] = broke[x][y] + 1;
					}
				}
			}
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < N; j++) {
			if (a[j] == '0') {
				miro[i][j] = false;
			}
			else if (a[j] == '1') {
				miro[i][j] = true;
			}	
		}
	}

	BFS(N, M);

	cout << broke[M-1][N-1] << "\n";

	return 0;
}