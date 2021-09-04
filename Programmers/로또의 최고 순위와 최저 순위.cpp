#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt=0;
    int correct_cnt=0;
    
    // win_nums 배열 sorting
    for(int i=0;i<win_nums.size()-1;i++){
        for(int j=i;j<win_nums.size();j++){
            if(win_nums[i]>win_nums[j]){
                int temp=win_nums[j];
                win_nums[j]=win_nums[i];
                win_nums[i]=temp;
            }
        }
    }
    
    // lottos 배열 sorting
    for(int i=0;i<lottos.size()-1;i++){
        for(int j=i;j<lottos.size();j++){
            if(lottos[i]>lottos[j]){
                int temp=lottos[j];
                lottos[j]=lottos[i];
                lottos[i]=temp;
            }
        }
    }
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0){
            zero_cnt++;
        }
    }
    
    int idx1=zero_cnt;
    int idx2=0;
    while(idx1!=6 && idx2!=6){
        if(lottos[idx1] == win_nums[idx2]){
            correct_cnt++;
            idx1++;
            idx2++;
        }
        else if(lottos[idx1]<win_nums[idx2]){
            idx1++;
        }
        else if(lottos[idx1]>win_nums[idx2]){
            idx2++;
        }
    }
    
    if(correct_cnt+zero_cnt==1 || correct_cnt+zero_cnt==0){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-(correct_cnt+zero_cnt));
    }
    
    if(correct_cnt==1 || correct_cnt==0){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-correct_cnt);
    }
    return answer;
}