#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int find(int temp, vector<int> &arr){
    int tmp = temp;
    while(arr[temp]!=temp){
        temp = arr[temp];
    }
    arr[tmp] = temp;
    return temp;
}

void merge(vector<int> &arr, int le, int ri){
    int a = find(le, arr);
    int b = find(ri, arr);
    arr[b] = a;
    arr[ri] = a;
    arr[le] = a;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n+1);
    int flag, ri, le;
    
    for(int i=0;i<=n;i++){
        arr[i] = i;
    }
    
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &flag, &le, &ri);
        if(!flag){
            merge(arr, le, ri);
        }
        else {
            if(find(le, arr) == find(ri, arr)){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    
    return 0;
}
