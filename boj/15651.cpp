#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void st(vector<int> arr, int now, int num, int m, int n){
    arr[num] = now;
    num++;
    if(num==m){
        for(int i=0;i<m;i++){
            printf("%d", arr[i]);
            if(i==m-1) printf("\n");
            else printf(" ");
        }
        return;
    }
    for(int i=1;i<=n;i++){
        st(arr, i, num, m, n);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(m);
    
    for(int i=0;i<n;i++){
        st(arr, i+1, 0, m, n);
    }
    
    return 0;
}
