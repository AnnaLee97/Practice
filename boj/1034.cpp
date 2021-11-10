#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second) return a.first.length() < b.first.length();
    else return a.second > b.second;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    string s;
    cin >> n >> m;
    char c;
    map<string, int> dic;
    
    for(int i=0;i<n;i++){
        s = "";
        for(int j=0;j<m;j++){
            cin >> c;
            
            if(c =='0') s+= j+'0';
        }
        dic[s]++;
    }
    cin >> k;
    
    vector<pair<string, int>> arr(dic.begin(), dic.end());
    sort(arr.begin(), arr.end(), compare);
    
    int count = 0, len;
    bool flag = false;
    for(int i=0;i<arr.size();i++){
        len = arr[i].first.length();
        
        if(len <= k){
            if((k-len)%2 == 0){
                count = arr[i].second;
                cout << count;
                flag = true;
                break;
            }
        }
    }
    if(!flag) cout<<0;
    
    return 0;
}
