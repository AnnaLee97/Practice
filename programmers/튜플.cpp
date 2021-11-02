#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string temp = "";
    map<int, int> dic;
    
    for(int i=0;i<s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            temp += s[i];
        } else {
            if(temp.length() != 0){
                dic[stoi(temp)]++;
            }
            temp = "";
        }
    }
    
    vector<pair<int, int>> tmp(dic.begin(), dic.end());
    sort(tmp.begin(), tmp.end(), compare);
    
    for(int i=0;i<tmp.size();i++){
        answer.push_back(tmp[i].first);
    }
    
    return answer;
}
