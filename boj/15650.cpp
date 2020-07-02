#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void st(vector<int> temp, vector<int> check, int now, int n, int m, int sel){
    temp[sel] = now;
    check[now-1] = 1;
    sel++;
    if(now == n && sel<m) return;
    if(sel == m){
        for(int i=0;i<temp.size(); i++){
            printf("%d", temp[i]);
            if(i==temp.size()-1) printf("\n");
            else printf(" ");
        }
        return;
    }
    for(int i=now+1; i<=n;i++){
        if(check[i-1]) continue;
        st(temp, check, i, n, m , sel);
    }
}

int main(){
    int m,n;
    scanf("%d %d", &n, &m);
    vector<int> check(n,0);
    vector<int> temp(m);
    
    for(int i=1;i<=n-m+1;i++){
        st(temp, check, i, n, m , 0);
    }
    
    
    return 0;
}
