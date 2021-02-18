// 规过 1 : 牢立府胶飘
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//bool check[1001];
//vector<int> num[1001];
//
//void DFS(int x) {
//	check[x] = true;
//	cout << x << " ";
//	for (int i = 0; i < num[x].size(); i++) {
//		int y = num[x][i];
//		if (check[y] == false) {
//			DFS(y);
//		}
//	}
//}
//
//void BFS(int x) {
//	queue <int> q;
//
//	check[x] = true;
//	q.push(x);
//
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		cout << x << " ";
//		for (int i = 0; i < num[x].size(); i++) {
//			int y = num[x][i];
//			if (check[y] == false) {
//				check[y] = true;
//				q.push(y);
//			}
//		}
//	}
//
//}
//
//int main() {
//
//	int N, M, V;
//	cin >> N >> M >> V;
//
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		cin >> a >> b;
//		num[a].push_back(b);
//		num[b].push_back(a);
//	}
//
//	for (int i = 0; i < N; i++) {
//		sort(num[i].begin(), num[i].end());
//	}
//
//	DFS(V);
//	cout << "\n";
//
//	for (int i = 0; i <= N; i++) {
//		check[i] = false;
//	}
//
//	BFS(V);
//
//	return 0;
//}

// 规过 2 : 牢立 青纺
#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int num[1001][1001];
bool check[1001];

void DFS(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i <= N; i++) {
		if (check[i] == false && num[x][i] == 1) {
			DFS(i);
		}
	}

}

void BFS(int x) {
	queue <int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty()) {
		int y = q.front();
		q.pop();
		cout << y << " ";

		for (int i = 0; i <= N; i++) {
			if (num[y][i] == 1 && check[i]==false) {
				q.push(i);
				check[i] = true;
			}
		}
	}
}

int main() {
	
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		num[a][b] = 1;
		num[b][a] = 1;
	}

	DFS(V);
	cout << "\n";

	for (int i = 0; i <= N; i++) {
		check[i] = false;
	}

	BFS(V);

	return 0;
}