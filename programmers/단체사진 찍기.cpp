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
