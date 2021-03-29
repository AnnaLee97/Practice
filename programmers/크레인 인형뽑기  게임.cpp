#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    int len = board[0].size();
    vector<int> arr(len, 0);
    
    for(int i=0; i<len; i++){
        for(int j=0;j<len;j++){
            if(board[j][i]){
                arr[i]=j;
                break;
            }
        }
    }
    
    int temp;
    int n;
    for(int i=0;i<moves.size();i++){
        temp = moves[i]-1;
        if(arr[temp] < len){
            n = board[arr[temp]][temp];
            arr[temp]++;
            if(n == 0) continue;
            if(!st.empty() && st.top()==n){
                st.pop();
                answer+=2;
            }
            else{
                st.push(n);
            }
        }
        
    }
    
    return answer;
}
