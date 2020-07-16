#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int t, n;
    scanf("%d\n", &t);
    vector<long long int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    
    for(int tc = 0;tc<t;tc++){
        scanf("%d", &n);
        if(n > arr.size()){
            int now = arr.size();
            for(int i=0;i<n-now;i++){
                arr.push_back(arr[arr.size()-2]+ arr[arr.size()-3]);
            }
            printf("%lld\n", arr.back());
        }
        else{
            printf("%lld\n", arr[n-1]);
        }
    }
    
    return 0;
}
