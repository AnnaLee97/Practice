#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void bfs(int &max, vector<vector<int>> wire, vector<int> check, queue<int> q){
    int now;
    int count = 0;
    int temp = q.front();
    
    while(!q.empty()){
        now = q.front();
        if(check[now]==0){
            count++;
            check[now]++;
            for(int i=0;i<wire[now].size();i++){
                q.push(wire[now][i]);
            }
        }
        q.pop();
    }
    if(max > abs((int)(check.size()-1-2*count))){
        max = abs((int)(check.size()-1-2*count));
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    queue<int> q;
    
    for(int i=0;i<wires.size();i++){
        vector<vector<int>> wire(n+1);
        vector<int> check(n+1, 0);
        
        for(int j=0;j<wires.size();j++){
            if(i==j) continue;
            wire[wires[j][0]].push_back(wires[j][1]);
            wire[wires[j][1]].push_back(wires[j][0]);
        }
        q.push(wires[i][0]);
        bfs(answer, wire, check, q);
        q.pop();
    }
    
    return answer;
}
