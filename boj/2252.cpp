#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> check(n+1, 0);
    vector<vector<int>> v(n+1);
    
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        
        v[a].push_back(b);
        check[b]++;
    }
    
    queue<int> q;
    int now, count = 0;
    for(int i=1;i<=n;i++){
        if(check[i] == 0){
            q.push(i);
            check[i] = -1;
            break;
        }
    }
    
    vector<int> ret;
    while(!q.empty()){
        now = q.front();
        q.pop();
        count++;
        ret.push_back(now);
        
        for(int i=0;i<v[now].size();i++){
            check[v[now][i]]--;
        }
        
        for(int i=1;i<=n;i++){
            if(check[i] == 0){
                q.push(i);
                check[i] = -1;
            }
        }
    }
    
    if(count < n){ //can't sort
        cout << "-1\n";
    }
    
    for(int i=0;i<n;i++){
        cout << ret[i];
        if(i!=n-1) cout << " ";
    }
    
    return 0;
}
