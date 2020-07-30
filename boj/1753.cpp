#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>


using namespace std;

int main(){
    int V,E;
    scanf("%d %d\n", &V, &E);
    int n;
    scanf("%d\n", &n);
    int u,v,w;
    vector<int> arr(V+1,9999999);
    vector<vector<pair<int, int>>> road(V+1);
    
    for(int i=0;i<E;i++){
        scanf("%d %d %d", &u, &v, &w);
        road[u].push_back(make_pair(w, v));
    }
    
    int now = n;
    priority_queue<pair<int,int>> q;
    
    arr[now]=0;
    q.push(make_pair(0,now));
    int temp;
    while(!q.empty()){
        now = q.top().second;
        q.pop();
        for(int j=0; j<road[now].size();j++){
            temp = arr[now]+road[now][j].first;
            if(arr[road[now][j].second] > temp){
                arr[road[now][j].second] = temp;
                q.push(make_pair(-temp,road[now][j].second));
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(arr[i] == 9999999){
            printf("INF\n");
        }
        else
            printf("%d\n", arr[i]);
    }
}
