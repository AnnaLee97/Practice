#include <string>
#include <vector>
#include <list>


using namespace std;

vector<list<char>> arr;

vector<vector<bool>> check(bool &flag){
    flag = false;
    vector<vector<bool>> ret;
    vector<vector<char>> board;
    
    
    for(int i=0;i<arr.size();i++){
        vector<char> c(arr[i].begin(), arr[i].end());
        board.push_back(c);
        
        vector<bool> temp(arr[i].size(), false);
        ret.push_back(temp);
    }
    
    for(int i=0;i<(int)board.size()-1;i++){
        for(int j=0;j<(int)board[i].size()-1;j++){
    
            if(board[i][j] == board[i][j+1] && 
               j < board[i+1].size() && board[i][j] == board[i+1][j] && 
               j+1 < board[i+1].size() && board[i][j] == board[i+1][j+1]){
                
                ret[i][j] = true;
                ret[i][j+1] = true;
                ret[i+1][j] = true;
                ret[i+1][j+1] = true;
                flag = true;
                
            } 
        }
    }
    
    return ret;
}
            
int remove(vector<vector<bool>> ret){
    int count = 0;
    for(int i=0;i<arr.size();i++){
        int j=0;
        for(auto it = arr[i].begin();it!=arr[i].end();j++){
            auto tempit = it++;
            if(ret[i][j]){
                arr[i].erase(tempit);
                count++;
            }
        }
    }
    return count;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag;
    
    for(int i=0;i<n;i++){
        list<char> li;
        arr.push_back(li);
        for(int j=0;j<m;j++){
            arr[i].push_back(board[m-j-1][i]);
        }
    }
    
    flag = true;

    while(flag){
        vector<vector<bool>> ret = check(flag);
        
        if(flag){
            answer += remove(ret);
        }
    }
    
    return answer;
}
