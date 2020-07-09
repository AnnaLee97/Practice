#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> arr1, pair<int, int> arr2){
    if(arr1.second == arr2.second){
        return arr1.first < arr2.first;
    }
    else return arr1.second < arr2.second;
}

int main(){
    int n;
    scanf("%d", &n);
    int start, end;
    vector<pair<int, int>> arr(n);
    
    for(int i=0;i<n;i++){
        scanf("%d %d", &start, &end);
        arr[i]=make_pair(start, end);
    }
    
    sort(arr.begin(), arr.end(), compare);
    int count = 1;
    pair<int, int> temp = arr[0];
    for(int i=1;i<n;i++){
        if(temp.second <= arr[i].first){
            temp = arr[i];
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
