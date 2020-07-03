#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<unsigned long long int> arr(n+1);
    if(n==0){
        printf("0\n");
        return 0;
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    printf("%llu\n", arr[n]);
    return 0;
}
