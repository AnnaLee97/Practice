#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n+1);
    vector<int> check(n+1, 0);
    
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        check[b]++;
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(check[i] == 0){
            check[i] = -1;
            q.push(i);
            break;
        }
    }
    
    vector<int> ret;
    int now;
    while(!q.empty()){
        now = q.front();
        ret.push_back(now);
        q.pop();
        
        for(int i=0;i<v[now].size();i++){
            check[v[now][i]]--;
        }
        
        for(int i=1;i<=n;i++){
            if(check[i] == 0){
                q.push(i);
                check[i] = -1;
                break;
            }
        }
    }
    
    for(int i=0;i<ret.size();i++){
        cout << ret[i];
        if(i!=n-1) cout << " ";
    }
    
    return 0;
}
