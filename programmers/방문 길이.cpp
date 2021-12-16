#include <string>
#include <vector>
#include <unordered_map>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using namespace std;

unordered_map<string, int> m;

void put(int row, int col, char c){
    string s = "";
    int nrow=row, ncol = col;
    
    if(c == 'U') nrow++;
    else if(c == 'L') ncol--;
    else if(c == 'D') nrow--;
    else ncol++;
    
    if(row == nrow){
        s += to_string(row) + to_string(min(col, ncol)) + " ";
        s += to_string(row) + to_string(max(col, ncol));
    }
    else {
        s += to_string(min(row, nrow)) + to_string(col) + " ";
        s += to_string(max(row, nrow)) + to_string(col);
    }
    
    m[s]++;
    
    return;
}

int solution(string dirs) {
    int answer = 0;
    int row=0, col=0;
    
    for(int i=0;i<dirs.length();i++){
        if(dirs[i] == 'U'){
            if(row+1 <= 5){
                put(row++, col, dirs[i]);
            }
        }
        else if(dirs[i] == 'D'){
            if(row-1 >= -5){
                put(row--, col, dirs[i]);
            }
        }
        else if(dirs[i] == 'L'){
            if(col-1 >= -5){
                put(row, col--, dirs[i]);
            }
        }
        else if(dirs[i] == 'R'){
            if(col+1 <= 5){
                put(row, col++, dirs[i]);
            }
        }
    }
    
    answer = m.size();
    
    return answer;
}
