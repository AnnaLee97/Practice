#include <iostream>
#include <vector>
#define inf 10000001
#define min(a, b) (a < b ? a : b)

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n+1, vector<int>(n+1, inf));
    
    int a, b, c;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;
        v[a][b] = min(v[a][b], c);
    }
    
    for(int i=1;i<=n;i++){
        v[i][i] = 0;
    }
    
    for(int now=1;now<=n;now++){
        for(int i=1;i<=n;i++){
            if(now == i) continue;
            for(int j=1;j<=n;j++){
                if(now==j) continue;
            
                v[i][j] = min(v[i][j], v[i][now]+v[now][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j] == 0 || v[i][j] >= inf) cout << 0;
            else cout << v[i][j];
            
            if(j!=n) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
