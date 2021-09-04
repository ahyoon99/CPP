#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string min_result="\0";
    string result="\0";
    
    if(s.length()==1){
        answer = s.length();
    }
    else{
        for(int i=1;i<=s.length()/2;i++){   // 끊어 읽는 단위
            int idx=0;  // 현재 idx
            result="\0";
            while(idx <= s.length()-1){
                int same_cnt=1;
                string prev="\0";
            
                for(int k=0;k<i;k++){
                    if(s[idx+k]=='\0'){
                        break;
                    }
                    else{
                        prev+=s[idx+k];
                    }
                }
                idx+=i;
                bool check=true;
            
                while(check){
                
                    for(int k=0;k<i;k++){
                        if(prev[k] == s[idx+k]){
                        }
                        else{
                            check=false;
                            break;
                        }
                    }
                    if(check==true){
                        same_cnt++;
                        idx+=i;
                    }
                    else{
                        break;
                    }
                }
                if(same_cnt>1){
                    result += to_string(same_cnt)+prev;
                }
                else if(same_cnt==1){
                    result+=prev;
                }
            }
            if(i==1){
                min_result=result;
            }
            else{
                if(min_result.length()>result.length()){
                    min_result=result;
                }
            }
        }
        answer=min_result.length();
    }
    return answer;
}