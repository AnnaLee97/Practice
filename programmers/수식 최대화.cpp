#include <string>
#include <vector>
#include <utility>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>


using namespace std;

map<char, int> m;

list<pair<bool, long long>> split(string exp);

void cal(string exp, long long &ans){
    string pri = "-+*";
    
    sort(pri.begin(), pri.end());
    
    do{        
        list<pair<bool, long long>> li = split(exp);
        
        for(int i=2;i>=0;i--){
            for(auto it=li.begin();it!=li.end();it++){
                if(it->first == true && it->second == pri[i]){
                    auto previt = prev(it);
                    auto nowit = it++;
                    
                    if(pri[i] == '*'){
                        (it->second) *= previt->second;
                    }
                    else if(pri[i] == '+'){
                        (it->second) += previt->second;
                    }
                    else (it->second) = previt->second - it->second;
                    
                    li.erase(previt);
                    li.erase(nowit);
                }
            }
        }
        
        if(li.front().second < 0) li.front().second *= -1;
        if(li.front().second > ans) ans = li.front().second;
        
    }while(next_permutation(pri.begin(), pri.end()));
}

list<pair<bool, long long>> split(string exp){
    list<pair<bool, long long>> li;
    string s = "";
    
    for(int i=0;i<exp.length();i++){
        if(exp[i] == '-' || exp[i] == '+' || exp[i] == '*'){
            li.push_back(make_pair(false, stoi(s)));
            li.push_back(make_pair(true, exp[i]));
            s = "";
        }
        else {
            s += exp[i];
        }
    }
    li.push_back(make_pair(false, stoi(s)));
    
    return li;
}

long long solution(string expression) {
    long long answer = 0;
    
    cal(expression, answer);
    
    return answer;
}
