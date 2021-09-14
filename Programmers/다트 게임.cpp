#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3]={0,};

    int idx=0;
    for(int i=0;i<3;i++){
        if(dartResult[idx] >= '0' && dartResult[idx] <='9'){
            if(dartResult[idx]=='1' && dartResult[idx+1]=='0'){
                score[i]=10;
                idx+=2;    
            }
            else{
                score[i]=dartResult[idx]-'0';
                idx+=1;
            }
        }
        
        int num = score[i];
        if(dartResult[idx]=='S'){
             
        }
        else if(dartResult[idx]=='D'){
            score[i]=num*num;
        }
        else if(dartResult[idx]='T'){
            score[i]=num*num*num;
        }
        idx++;
        
        if(dartResult[idx] >= '0' && dartResult[idx] <='9'){
            continue;
        }
        else{
            if(dartResult[idx]=='*'){
                if(i==0){
                    score[i]=score[i]*2;
                }
                else if(i>0){
                    score[i]=score[i]*2;
                    score[i-1]=score[i-1]*2;
                }
            }
            else if(dartResult[idx]=='#'){
                score[i]=-score[i];
            }
            idx++;
        }
        
        
    }
    
    for(int i=0;i<3;i++){
        answer += score[i];
    }
    
    return answer;
}