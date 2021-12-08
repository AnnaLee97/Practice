#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
    
    int row = 0, col = 0;
    int now = 1;
    for(int count=n; count >=1; count--){
        if((n-count) % 3 == 0){ //go down
            for(int i=0;i<count;i++){
                board[row+i][col] = now++;
            }
            row += count-1;
        }
        else if((n-count) % 3 == 1){ //go right
            for(int i=1;i<=count;i++){
                board[row][col+i] = now++;
            }
            col += count;
        }
        else { //go up
            for(int i=1;i<=count;i++){
                board[row-i][col-i] = now++;
            }
            row -= count; row++;
            col -= count;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}
