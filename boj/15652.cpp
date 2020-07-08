#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void st(vector<int> arr, int now, int num, int n, int m){
    arr[num] = now;
    num++;
    if(num == m){
        for(int i=0;i<m;i++){
            printf("%d", arr[i]);
            if(i!=m-1) printf(" ");
        }
        printf("\n");
        return;
    }
    
    for(int i=now;i<=n;i++){
        st(arr, i, num, n, m);
    }
    return;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(m);
    
    for(int i=1;i<=n;i++){
        st(arr, i, 0, n, m);
    }
    
    return 0;
}
