#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> le, pair<int, int> ri){
    if(le.second == ri.second)
        return le.first < ri.first;
    else return le.second < ri.second;
}

int main(){
    int n;
    scanf("%d\n", &n);
    int left, right;
    vector<pair<int, int>> arr;
    for(int i=0;i<n;i++){
        scanf("%d %d", &left, &right);
        arr.push_back(make_pair(left,right));
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for(int i=0;i<n;i++){
        printf("%d %d\n", arr[i].first, arr[i].second);
    }
    
    return 0;
}
