#include <string>
#include <vector>

using namespace std;

vector<char> removeDot(vector<char> id) {
    int start_idx = 0;
    int end_idx = 0;

    // .이 처음에 위치한 경우 제거해준다.
    while (id.size()!=0) {
        int i = 0;
        if (id[i] == '.') {
            id.erase(id.begin() + i);
        }
        else {
            break;
        }
    }

    // .이 끝에 위치한다면 제거해준다.
    while (id.size() != 0) {
        int i = id.size() - 1;
        if (id[i] == '.') {
            id.erase(id.begin() + i);
        }
        else {
            break;
        }
    }

    return id;
}

vector<char> checkChar(vector<char> id) {

    int i = 0;
    while (id.size()!=i) {   // 주어진 문자 외의 것이 있다면 제거해준다.
        if ((id[i] >= 'a' and id[i] <= 'z') || (id[i] >= '0' and id[i] <= '9') || id[i] == '-' || id[i] == '_' || id[i] == '.') {
            i++;
            continue;
        }
        else {
            id.erase(id.begin() + i);
        }
    }
    return id;
}

vector<char> mergeDot(vector<char> id) {
    int i = 0;
    while (id.size() != i + 1) {   // 주어진 문자 외의 것이 있다면 제거해준다.
        if (id[i] == '.') {
            if (id[i + 1] == '.') {
                id.erase(id.begin() + i);
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }
    return id;
}

string solution(string new_id) {
    string answer = "";
    vector<char> id;

    for (int i = 0; i < new_id.length(); i++) { // vector에 id값 넣어주었다.
        if (new_id[i] >= 65 && new_id[i] <= 90) {   // 대문자 알파벳은 소문자 알파벳으로 변환.
            id.push_back(char(new_id[i] + 32));
        }
        else {
            id.push_back(new_id[i]);
        }
    }

    id = checkChar(id);
    id = mergeDot(id);
    id = removeDot(id);


    if (id.size() == 0) {
        return "aaa";
    }
    else if (id.size() >= 16) {
        int i = 15;
        while (id.size()!=15) {
            id.erase(id.begin() + i);
        }
        id = checkChar(id);
        id = mergeDot(id);
        id = removeDot(id);

    }
    else if (id.size() <= 2) {
        while (id.size() != 3) {
            int idx = id.size();
            id.push_back(id[idx - 1]);
        }
    }

    for (int i = 0; i < id.size(); i++) {
        answer += id[i];
    }

    return answer;
}