#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> values;
    map<int, int> m;
    int temp;
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> temp;
        values.push_back(temp);
        sum += temp;
        if(m.find(temp) == m.end()){
            m[temp] = 1;
        } else m[temp]++;
    }
    
    sort(values.begin(), values.end());
    cout << floor(0.5 + (double)sum/n);
    cout <<"\n";
    cout << values[n/2];
    cout <<"\n";
    
    vector<pair<int, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), compare);
    
    if(v.size() > 1 && v[0].second == v[1].second){
        cout << v[1].first;
    } else cout << v[0].first;
    cout << "\n";
    
    cout <<values[n-1] - values[0];
    cout <<"\n";
    
    
    return 0;
}
