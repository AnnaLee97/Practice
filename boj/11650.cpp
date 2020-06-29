#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> t, pair<int, int> tt){
    if(t.first == tt.first){
        return t.second < tt.second;
    }
    else return t.first < tt.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);
    
    for(int i=0;i<n;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}
