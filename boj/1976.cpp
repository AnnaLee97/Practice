#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

int find(vector<int> &check, int now){
    int temp = now;
    
    while(check[temp] != temp){
        temp = check[temp];
    }
    
    check[now] = temp;
    return temp;
}

void merge(vector<int> &check, int le, int ri){
    int l = find(check, le);
    int r = find(check, ri);
    
    check[r] = l;
}

int main(){
    int n, m;
    scanf("%d\n%d\n", &n, &m);
    vector<int> check(n+1);
    for(int i=1;i<=n;i++){
        check[i] = i;
    }
    
    int temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &temp);
            if(j<i && temp){
                merge(check, i, j);
            }
        }
    }
    
    int t;
    int flag = 0;
    scanf("%d", &temp);
    t = find(check, temp);
    for(int i=1;i<m;i++){
        scanf("%d", &temp);
        if(t != find(check, temp)){
            flag = 1;
            break;
        }
    }
    
    if(!flag){
    	printf("YES\n");
    }
    else printf("NO\n");
    
    return 0;
}
