#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<int> &visit, vector<vector<int>> arr, int now){
    visit[now]++;
    printf("%d", now);
    if(arr[now].empty()){
        return;
    }
    printf(" ");
    for(int i=0;i<arr[now].size();i++){
        if(visit[arr[now][i]]) continue;
        dfs(visit, arr, arr[now][i]);
    }
    return;
}

void bfs(vector<int> &visit, vector<vector<int>> arr, int now){
    queue<int> q;
    q.push(now);
    while(!q.empty()){
        now = q.front();
	    if(!visit[now]){
	        visit[now]++;
	        printf("%d ", now);
	        for(int i=0; i<arr[now].size();i++){
	            q.push(arr[now][i]);
	        }
        }
        q.pop();
    }
    printf("\n");
}

int main(){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    vector<vector<int>> arr(n+1);
    int t, tm;
    for(int i=0;i<m;i++){
        scanf("%d %d", &t, &tm);
        arr[t].push_back(tm);
        arr[tm].push_back(t);
    }
    
    for(int i=1;i<=n;i++){
        if(arr[i].size()!=0){
            sort(arr[i].begin(), arr[i].end());
        }
    }
    
    vector<int> visit(n+1,0);
    dfs(visit, arr, v);
    vector<int> visit2(n+1,0);
    printf("\n");
    bfs(visit2, arr, v);
    
    return 0;
}
