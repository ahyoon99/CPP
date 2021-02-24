// 방법 1 : 2개의 큐 이용
#include <iostream>
#include <queue>
using namespace std;

bool check[100001];
int dist[100001];

void BFS(int N) {
	queue <int> q1;
	queue <int> q2;

	q1.push(N);
	check[N] = true;
	dist[N] = 0;

	while (!q1.empty()) {
		int a = q1.front();
		q1.pop();

		if (a * 2 < 100001) {
			if (check[a * 2] == false) {
				q1.push(a * 2);
				check[a * 2] = true;
				dist[a * 2] = dist[a];
			}
		}
		if (a + 1 < 100001) {
			if (check[a + 1] == false) {
				q2.push(a + 1);
				check[a + 1] = true;
				dist[a + 1] = dist[a] + 1;
			}
		}
		if (a - 1 >= 0) {
			if (check[a - 1] == false) {
				q2.push(a - 1);
				check[a - 1] = true;
				dist[a - 1] = dist[a] + 1;
			}
		}

		if (q1.empty()) {
			q1 = q2;
			q2 = queue <int>();
		}
	}
}

int main() {

	int N, K;
	cin >> N >> K;

	BFS(N);

	cout << dist[K] << "\n";

	return 0;
}