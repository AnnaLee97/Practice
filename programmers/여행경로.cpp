#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

void go(vector<string> &answer, vector<string> temp, map<string, map<string, int>> check, string now, int count){  
    if(answer.size() != 0) return;
    
    temp.push_back(now);
    
    if(check[now].size() == 0){
        if(temp.size() == count){
            answer.assign(temp.begin(), temp.end());
            return;
        } else return;
    }
    
    string name;
    int val;
    for(auto it=check[now].begin();it!=check[now].end();){
        name = it->first;
        val = it->second;
        auto ittemp = it;
        
        if(val > 1){
            it->second -= 1;
        } else {
            it++;
            check[now].erase(ittemp);
        }
        
        go(answer, temp, check, name, count);
        if(answer.size() != 0) return;
        check[now][name] = val;
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, map<string, int>> check;
    int count = 0;
    
    for(int i=0;i<tickets.size();i++){
        count++;
        if(check[tickets[i][0]].find(tickets[i][1]) == check[tickets[i][0]].end()){
            check[tickets[i][0]][tickets[i][1]] = 1;
        } else 
            check[tickets[i][0]][tickets[i][1]] += 1;
    }
    
    go(answer, {}, check, "ICN", count+1);
    
   
    
    return answer;
}
