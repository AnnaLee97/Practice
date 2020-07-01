#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

void st(vector<int> arr, vector<int> res, vector<int> check,int num, int m, int n, int now){
    res[num]=arr[now];
    check[now]++;
    num++;
    if(num == m){
        for(int i=0; i<m; i++){
            printf("%d", res[i]);
            if(i==m-1){
                printf("\n");
            }
            else printf(" ");
        }
        return;
    }
    
    for(int j=0; j<n; j++){
        if(check[j]) continue;
        st(arr, res, check, num, m, n, j);
    }
    return;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    vector<int> temp(m);
    vector<int> check(n,0);
    
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    
    for(int i=0 ;i<n;i++)
        st(arr, temp, check, 0, m, n, i);
    
    return 0;
}
