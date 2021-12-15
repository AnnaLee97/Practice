#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>


using namespace std;

void check(int &ret, vector<string> data, string s){
    unordered_map<char, int> dic;
    
    for(int i=0;i<s.length();i++){
        dic[s[i]] = i;
    }
    
    int temp, val;
    for(int i=0;i<data.size();i++){
        temp = abs(dic[data[i][0]] - dic[data[i][2]])-1;
        val = data[i][4]-'0';
        
        if(data[i][3] == '=' && val != temp) return;
        if(data[i][3] == '>' && temp <= val) return;
        if(data[i][3] == '<' && temp >= val) return;
    }
    
    ret++;
    return;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string s = "ACFJMNRT";
    
    do{
        check(answer, data, s);
    } while(next_permutation(s.begin(), s.end()));
    
    
    return answer;
}


---------------------------------------------------------------------------
    
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>


using namespace std;

int toindex(char c);

void check(int &ret, vector<vector<pair<int, int>>> condition, string s){
    vector<int> dic(8);
    
    for(int i=0;i<s.length();i++){
        dic[toindex(s[i])] = i;
    }
    
    int temp, val;
    for(int i=0;i<condition.size();i++){
        for(int j=i+1;j<condition.size();j++){
            temp = abs(dic[i] - dic[j])-1;
            
            if(temp < condition[i][j].first || condition[i][j].second < temp) return;
        }
    }
    
    ret++;
    return;
}

int toindex(char c){
    if(c == 'A') return 0;
    else if(c == 'C') return 1;
    else if(c == 'F') return 2;
    else if(c == 'J') return 3;
    else if(c == 'M') return 4;
    else if(c == 'N') return 5;
    else if(c == 'R') return 6;
    else if(c == 'T') return 7;
}


int solution(int n, vector<string> data) {
    int answer = 0;
    string s = "ACFJMNRT";
    pair<int, int> p = make_pair(0, 7);
    vector<vector<pair<int, int>>> condition(8, vector<pair<int, int>>(8, p));
    
    int a, b, val;
    for(int i=0;i<data.size();i++){
        a = toindex(data[i][0]);
        b = toindex(data[i][2]);
        val = data[i][4] - '0';
        
        if(data[i][3] == '='){
            if(condition[a][b].first <= val && val <= condition[a][b].second){
                condition[a][b].first = val;
                condition[a][b].second = val;
                condition[b][a].first = val;
                condition[b][a].second = val;
            }
            else return answer;
        }
        else if(data[i][3] == '>'){
            if(val >= condition[a][b].second) return answer;
            else if(val >= condition[a][b].first){
                condition[a][b].first = val+1;
                condition[b][a].first = val+1;
            }
        }
        else {
            if(val <= condition[a][b].first) return answer;
            else if(val <= condition[a][b].second){
                condition[a][b].second = val-1;
                condition[b][a].second = val-1;
            }
        }
    }
    
    
    do{
        check(answer, condition, s);
    } while(next_permutation(s.begin(), s.end()));
    
    
    return answer;
}
