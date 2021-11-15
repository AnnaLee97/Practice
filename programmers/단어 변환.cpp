#include <string>
#include <vector>
#include <map>


using namespace std;

void dfs(string now, string target, map<string, vector<string>> m, map<string, bool> check, int &ans, int t){
    check[now] = true;
    
    if(now == target){
        if(t < ans) ans = t;
        return;
    }
    
    for(int i=0;i<m[now].size();i++){
        if(!check[m[now][i]])
            dfs(m[now][i], target, m, check, ans, t+1);
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 52;
    map<string, vector<string>> m;
    map<string, bool> check;
    int count = 0;
    
    words.push_back(begin);
    
    for(int i=0;i<(int)words.size()-1;i++){
        check[words[i]] = false;

        for(int j=i+1;j<words.size();j++){
            check[words[j]] = false;
            count = 0;
            
            for(int k=0;k<words[j].length();k++){
                if(words[j][k] != words[i][k]) count++;
            }
            
            if(count == 1){
                m[words[i]].push_back(words[j]);
                m[words[j]].push_back(words[i]);
            }
        }
    }
    
    dfs(begin, target, m, check, answer, 0);
    
    if(answer == 52) answer = 0;
    
    return answer;
}
