// 1번째 방법 : 경우의 수 다 해보기
#include <iostream>
using namespace std;

int board[500][500];

int main() {

	int N, M;
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j + 3 < M) {	//1
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 3 < N) {	//2
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j + 1 < M) {	//3
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j - 1 >= 0) {	//4
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i - 1 >= 0 && j + 2 < M) {	//5
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j + 1 < M) {	//6
				int temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 2 < M) {	//7
				int temp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 2 < M) {	//8
				int temp = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j + 1 < M) {	//9
				int temp = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+2][j];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 2 < M) {	//10
				int temp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 1 < M) {	//11
				int temp = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j + 1 < M) {	//12
				int temp = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i - 1 >= 0 && j + 2 < M) {	//13
				int temp = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i - 1][j + 2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j - 1 >= 0) {	//14
				int temp = board[i][j] + board[i+1][j] + board[i+1][j-1] + board[i+2][j-1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 2 < M) {	//15
				int temp = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 1 < N && j + 2 < M) {	//16
				int temp = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i][j+2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j - 1 >= 0) {	//17
				int temp = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j-1];
				if (max < temp) {
					max = temp;
				}
			}
			if (i - 1 >= 0 && j + 2 < M) {	//18
				int temp = board[i][j] + board[i-1][j+1] + board[i][j+1] + board[i][j+2];
				if (max < temp) {
					max = temp;
				}
			}
			if (i + 2 < N && j + 1 < M) {	//19
				int temp = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j];
				if (max < temp) {
					max = temp;
				}
			}
		}
	}

	cout << max << "\n";

	return 0;
}