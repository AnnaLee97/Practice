#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void fib(vector<pair<int, int>> &arr, int n){
    arr[n].first = arr[n-1].first + arr[n-2].first;
    arr[n].second = arr[n-1].second + arr[n-2].second;
    return;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<pair<int, int>> arr(41, make_pair(0,0));
    int t, n, maxi = 1;
    cin >> t;
    
    arr[0].first = 1;
    arr[1].second = 1;
    
    for(int i=0;i<t;i++){
        cin >> n;
        if(n > maxi){
            for(int j=maxi+1;j<=n;j++){
                fib(arr, j);
            }
            maxi = n;
        }
        cout << arr[n].first << " " << arr[n].second <<"\n";
    }
    
    
    
    return 0;
}
