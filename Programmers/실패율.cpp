#include <string>
#include <vector>
#include <utility>

using namespace std;

class Num {
public:
    long long int bunja;
    long long int bunmo;

    Num() {
        bunja = 0;
        bunmo = 0;
    }
};

bool IsBigger(pair<int, Num> p1, pair<int, Num> p2) {
    if (p1.second.bunja == 0) {
        if (p2.second.bunja == 0) {
            if (p1.first < p2.first) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        if (p2.second.bunja == 0) {
            return true;
        }
        else {
            long long int med1 = p2.second.bunmo * p1.second.bunja;
            long long int med2 = p1.second.bunmo * p2.second.bunja;
            if (med1 > med2) {
                return true;
            }
            else if(med1<med2){
                return false;
            }
            else if (med1 == med2) {
                if (p1.first < p2.first) {
                    return true;
                }
                else {
                    return false;
                }
            }
            
        }
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int people[502] = { 0, };    // 각 스테이지에 도달한 플레이어 수
    pair<int, Num> ratio[502];

    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++) {
            people[j]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        ratio[i].first = i;
        ratio[i].second.bunja = people[i] - people[i + 1];
        ratio[i].second.bunmo = people[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            if (false == IsBigger(ratio[i], ratio[j])) {
                swap(ratio[i], ratio[j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        answer.push_back(ratio[i].first);
    }

    return answer;
}