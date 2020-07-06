#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int temp;
    vector<int> arr;
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &temp);
        if(temp>k) break;
        arr.push_back(temp);
    }
    int res = 0;
    for(int j=i-1;j>=0;j--){
        if(arr[j] <= k){
            res += k/arr[j];
            k = k%arr[j];
        }
    }
    printf("%d\n", res);
    return 0;
}
