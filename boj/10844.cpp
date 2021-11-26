#include <iostream>
#include <vector>

using namespace std;

void make(vector<vector<long long>> &v, int n){
    v[n][0] = v[n-1][1];
    for(int i=1;i<=8;i++){
        v[n][i] = (v[n-1][i-1] + v[n-1][i+1])%1000000000;
    }
    v[n][9] = v[n-1][8];
    return;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    
    cin >> n;
    long long ret = 0;
    vector<vector<long long>> v(n+1, vector<long long>(10, 1));
    
    for(int i=2;i<=n;i++){
        make(v, i);
    }
    
    for(int i=1;i<=9;i++){
        ret += v[n][i];
        ret %= 1000000000;
    }
    
    cout << ret << "\n";
    
    return 0;
}
