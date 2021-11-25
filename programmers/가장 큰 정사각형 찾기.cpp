#include <iostream>
#include <vector>
#define min(a,b) (a < b ? a : b)

using namespace std;


int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<vector<int>> check(board.begin(), board.end());
    int m;
    
    if(board.size() == 1 && board[0].size() == 1 && board[0][0]==1) return 1;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == 0) continue;
        
            if(i-1 >=0 && j-1 >=0){
                m = check[i-1][j];
                m = min(m, check[i][j-1]);
                m = min(m, check[i-1][j-1]);
            }
            else if(board.size() == 1 || board[0].size() == 1){
                m = 0;
            }
            else continue;
            
            check[i][j] = m+1;
            
            if(answer < check[i][j]){
                answer = check[i][j];
            }
        }
    }

    return answer * answer;
}
