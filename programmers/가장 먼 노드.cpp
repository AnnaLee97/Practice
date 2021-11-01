#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

void bfs(vector<vector<int>> arr, vector<int> &check){      
    queue<pair<int, int>> q;
    int now, len;
    
    q.push(make_pair(1, 1));
    check[1] = 1;
    
    while(!q.empty()){
        now = q.front().first;
        len = q.front().second;
        
        q.pop();
        
        if(len > check[now]) continue;
        
        for(int i=0;i<arr[now].size();i++){
            if(len+1 < check[arr[now][i]]){
                check[arr[now][i]] = len+1;
                q.push(make_pair(arr[now][i], len+1));
            }
        }
        
    }
    
    
    return;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    vector<vector<int>> arr(n+1);
    vector<int> check(n+1, n+2);
    
    for(int i=0;i<edge.size();i++){
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(arr, check);
    
    sort(check.begin(), check.end(), greater<int>());
    
    max = check[1];
    for(int i=1;i<check.size();i++){
        if(max == check[i]) answer++;
    }
    
    return answer;
}
