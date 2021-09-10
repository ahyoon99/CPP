#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int> s;

    for (int i = 0; i < moves.size(); i++) {
        int y_idx = moves[i] - 1;
        int x_idx = 0;
        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][y_idx] != 0) {
                x_idx = j;
                if (!s.empty() && s.top() == board[x_idx][y_idx]) {
                    answer += 2;
                    s.pop();
                }
                else {
                    s.push(board[x_idx][y_idx]);
                }
                board[x_idx][y_idx] = 0;
                break;
            }
        }
    }
    return answer;
}