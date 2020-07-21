#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int n;
    scanf("%d\n", &n);
    vector<int> check(n+1, 0);
    vector<vector<int>> arr(n+1);
    
    vector<int> res(n+1);

    int le,ri;
    for(int i=0;i<n-1;i++){
        scanf("%d %d", &le, &ri);
        arr[le].push_back(ri);
        arr[ri].push_back(le);
    }
    
    queue<int> q;
    q.push(1);
    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        check[now]++;
        for(int i=0;i<arr[now].size();i++){
            if(!check[arr[now][i]]){
                res[arr[now][i]] = now;
                q.push(arr[now][i]);
            }
        }
    }

    for(int i=2;i<=n;i++){
        printf("%d\n", res[i]);
    }
    
    return 0;
}
