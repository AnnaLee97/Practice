#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int n,s;
    scanf("%d %d\n", &n, &s);
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    int i=0,j=1;
    int len = n+1;
    long long sum = arr[0];
    while(true){
        if(sum < s){
            if(j==n){
                break;
            } else {
                sum += arr[j];
                j++;
            }
        } else {
            if(len > j-i) len = j-i;
            sum -= arr[i];
            i++;
        }
    }
    if(len ==n+1) len = 0;
    printf("%ld", len);
    
    return 0;
}
