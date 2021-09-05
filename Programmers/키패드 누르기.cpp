#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_cur=10; // 왼손의 현재 위치
    int right_cur=11;    // 오른손의 현재 위치
    
    int distance[4][13] = {
        {3,1,0,1,2,1,2,3,2,3,4,4},  // 2
        {2,2,1,2,1,0,1,2,1,2,3,3},  // 5
        {1,3,2,3,2,1,2,1,0,1,2,2},  // 8
        {0,4,3,4,3,2,3,2,1,2,1,1}   // 0
    };
    
   for(int i=0;i<numbers.size();i++){
       if(numbers[i]==1 ||numbers[i]==4 ||numbers[i]==7){
           left_cur = numbers[i];
           answer+="L";
       }
       else if(numbers[i]==3 ||numbers[i]==6 ||numbers[i]==9){
           right_cur = numbers[i];
           answer+="R";
       }
       else{
           int idx;
           if(numbers[i]==2){
               idx=0;
           }
           else if(numbers[i]==5){
               idx=1;
           }
           else if(numbers[i]==8){
               idx=2;
           }
           else if(numbers[i]==0){
               idx=3;
           }
           
           if(distance[idx][left_cur]<distance[idx][right_cur]){
               left_cur = numbers[i];
               answer+="L";
           }
           else if(distance[idx][left_cur]>distance[idx][right_cur]){
               right_cur=numbers[i];
               answer+="R";
           }
           else if(distance[idx][left_cur]==distance[idx][right_cur]){
               if(hand == "right"){
                   right_cur=numbers[i];
                   answer+="R";
               }
               else if(hand=="left"){
                   left_cur=numbers[i];
                   answer+="L";
               }
           }
       }
   }
    
    return answer;
}