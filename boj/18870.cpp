#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> tmp(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> tmp[i];
        s.insert(tmp[i]);
    }
    
    vector<int> arr(s.begin(), s.end());
    map<int, int> res;
    
    for(int i=0;i<arr.size();i++){
        res[arr[i]] = i;
    }
    
    cout << res[tmp[0]];
    for(int i=1;i<n;i++){
        cout << " " << res[tmp[i]];
    }
    return 0;
}
