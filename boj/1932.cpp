#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    vector<int> arr(n+1, 0);
    vector<int> tmp(n+1, 0);
    int temp;
    scanf("%d", &arr[1]);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d", &tmp[j]);
        }
        for(int j=i;j>0;j--){
            if(j==i){
                tmp[j] += arr[j-1];
            }
            else{
                tmp[j] += max(arr[j-1], arr[j]);
            }
        }
        for(int j=1;j<=i;j++){
            arr[j] = tmp[j];
        }
    }
    
    sort(arr.begin(), arr.end());
    printf("%d\n", arr[arr.size()-1]);
    
    
    return 0;
}
