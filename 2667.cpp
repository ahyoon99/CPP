// 방법 1 : DFS
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N;
//int cnt = 0;
//int house_cnt[626];
//bool town[27][27];
//int num_town[27][27];
//
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//void DFS(int x, int y, int cnt) {
//	num_town[x][y] = cnt;
//	house_cnt[cnt]++;
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (0 <= nx && nx <= N - 1 && 0 <= ny && ny <= N - 1) {
//			if (town[nx][ny] == 1 && num_town[nx][ny] == 0) {
//				DFS(nx, ny, cnt);
//				
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string input_num;
//		cin >> input_num;
//
//		for (int j = 0; j < N; j++) {
//			if (input_num[j] == '1') {
//				town[i][j] = true;
//			}
//			else if (input_num[j] == '0') {
//				town[i][j] = false;
//			}
//		}
//	}
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (town[i][j] == true && num_town[i][j] == 0) {
//				DFS(i, j, ++cnt);
//			}
//		}
//	}
//
//	cout << cnt << "\n";
//	sort(house_cnt+1, house_cnt + cnt+1);	// house_cnt배열은 index가 1부터 cnt까지 값이 들어있으니까 !
//	for (int i = 1; i <= cnt; i++) {
//		cout << house_cnt[i] << "\n";
//	}
//
//	return 0;
//}

// 방법 2 : BFS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
bool town[27][27];
int num_town[27][27];
int house_cnt[626];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void BFS(int x, int y, int cnt) {
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	num_town[x][y] = cnt;
	house_cnt[cnt]++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx <= N - 1 && 0 <= ny && ny <= N - 1) {
				if (town[nx][ny] == 1 && num_town[nx][ny] == 0) {
					BFS(nx, ny, cnt);
				}
			}
		}
	}
}

int main() {

	cin >> N;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < N; j++) {
			if (a[j] == '1') {
				town[i][j] = true;
			}
			else if (a[j] == '0') {
				town[i][j] = false;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (town[i][j] == 1 && num_town[i][j] == 0) {
				BFS(i, j, ++cnt);
			}
		}
	}

	cout << cnt << "\n";
	sort(house_cnt + 1, house_cnt + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << house_cnt[i] << "\n";
	}

	return 0;
}