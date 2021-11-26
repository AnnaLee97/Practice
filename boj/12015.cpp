#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    
    vector<int> ret;
    int ind;
    for(int i=0;i<v.size();i++){
        if(ret.size() == 0) ret.push_back(v[i]);
        else {
            if(ret[ret.size()-1] < v[i]){
                ret.push_back(v[i]);
            }
            else {
                ind = lower_bound(ret.begin(), ret.end(), v[i])-ret.begin();
                ret[ind] = v[i];
            }
        }
    }
    
    cout << ret.size()<<"\n";
    
    return 0;
}
