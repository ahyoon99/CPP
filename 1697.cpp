#include <iostream>
#include <queue>
using namespace std;

bool check[100001];
int dist[100001];

void BFS(int N, int K) {
	queue <int> q;
	q.push(N);
	check[N] = true;
	dist[N] = 0;

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (a - 1 >= 0) {
			if (!check[a - 1]) {
				q.push(a - 1);
				check[a - 1] = true;
				dist[a - 1] = dist[a] + 1;
			}
		}
		if (a + 1 <= 100000) {
			if (!check[a + 1]) {
				q.push(a + 1);
				check[a + 1] = true;
				dist[a + 1] = dist[a] + 1;
			}
		}
		if (2 * a <= 100000) {
			if (!check[2 * a]) {
				q.push(2 * a);
				check[2 * a] = true;
				dist[a * 2] = dist[a] + 1;
			}
		}
	}
}

int main() {

	int N, K;
	cin >> N >> K;

	BFS(N, K);

	cout << dist[K] << "\n";

	return 0;
}