// 规过 1 : BFS
//#include <iostream>
//#include <queue>
//using namespace std;
//
//bool island[51][51];
//int num_island[51][51];
//
//int dx[] = { 1,-1,0,0,-1 ,-1,1,1 };
//int dy[] = { 0,0,1,-1 ,-1,1,-1,1 };
//
//int cnt = 0;
//int w, h;
//
//void BFS(int x, int y, int cnt) {
//	queue <pair<int,int>> q;
//	q.push(make_pair(x, y));
//	num_island[x][y] = cnt;
//
//	while (!q.empty()) {
//		x = q.front().first;
//		y = q.front().second;
//		q.pop();
//		for (int i = 0; i < 8; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1) {
//				if (island[nx][ny] == 1 && num_island[nx][ny] == 0) {
//					num_island[nx][ny] = cnt;
//					q.push(make_pair(nx, ny));
//				}
//			}
//		}
//	}
//}
//
//int main() {
//
//	while (true) {
//		
//		cin >> w >> h;
//		if (w == 0 && h == 0) {
//			break;
//		}
//		else {
//
//			for (int i = 0; i < h; i++) {
//				for (int j = 0; j < w; j++) {
//					cin >> island[i][j];
//				}
//			}
//
//			for (int i = 0; i < h; i++) {
//				for (int j = 0; j < w; j++) {
//					if (island[i][j] == 1 && num_island[i][j] == 0) {
//						BFS(i, j, ++cnt);
//					}
//				}
//			}
//
//			cout << cnt << "\n";
//
//			for (int i = 0; i < h; i++) {
//				for (int j = 0; j < w; j++) {
//					island[i][j] = false;
//					num_island[i][j] = 0;
//				}
//			}
//			cnt = 0;
//		}
//	}
//
//	return 0;
//}

// 规过 2 : DFS
#include <iostream>
using namespace std;

bool island[51][51];
int num_island[51][51];
int cnt = 0;
int w, h;

int dx[] = { 1,-1,0,0,-1,1,1,-1 };
int dy[] = { 0,0,1,-1,-1,-1,1,1 };

void DFS(int x, int y, int cnt) {
	num_island[x][y] = cnt;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1) {
			if (island[nx][ny] == 1 && num_island[nx][ny] == 0) {
				DFS(nx, ny, cnt);
			}
		}
	}

}

int main() {

	while (true) {
		
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}
		else {

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cin >> island[i][j];
				}
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (island[i][j] == 1 && num_island[i][j] == 0) {
						DFS(i, j, ++cnt);
					}
				}
			}

			cout << cnt << "\n";

			cnt = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					island[i][j] = false;
					num_island[i][j] = 0;
				}
			}

		}
	}

	return 0;
}