#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void check(vector<pair<int, int>> &temp, vector<vector<int>> line, int now, vector<int> &rows, vector<int> &cols){
    long long x, y;
    long long div;
    for(int i=now+1; i<line.size();i++){
        div = (long long)line[now][0]*line[i][1] - (long long)line[now][1]*line[i][0];
        if(div != 0) {
            x = (long long)line[now][1]*line[i][2] - line[now][2]*line[i][1];
            if(x%div !=0) continue;
            y = (long long)line[now][2]*line[i][0] - line[now][0]*line[i][2];
            if(y%div !=0) continue;
            x /= div;
            y /= div;   

            temp.push_back(make_pair(x,y));
            rows.push_back(x);
            cols.push_back(y);
        } 
    }
}

vector<string> solution(vector<vector<int>> line) {
    vector<pair<int, int>> temp;
    vector<int> rows, cols;

    for(int i=0;i<line.size()-1;i++){
        check(temp, line, i, rows, cols);
    }

    int srow, scol, erow, ecol;

    scol = *min_element(rows.begin(), rows.end());
    ecol = *max_element(rows.begin(), rows.end());
    srow = *min_element(cols.begin(), cols.end());
    erow = *max_element(cols.begin(), cols.end());

    string str="";
    for(int i=scol; i<=ecol; i++){
        str += ".";
    }

    vector<string> answer(erow-srow+1, str);

    for(int i=0; i<temp.size(); i++){        
        answer[temp[i].second-srow][temp[i].first-scol] = '*';
    }
    reverse(answer.begin(), answer.end());

    return answer;
}
