#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    vector<map<int, int>> check(n+1);
    check[0][0] = 0;
    
    int t;
    for(int i=1;i<=n;i++){
        for(auto it=check[i-1].begin();it!=check[i-1].end();it++){
            t = it->first;
            //if not drink
            if(check[i].find(0) == check[i].end() || it->second > check[i][0]){
                check[i][0] = it->second;
            }
            
            //if drink
            if(t < 2){
                if(check[i].find(t+1) == check[i].end() || it->second +arr[i] > check[i][t]){
                    check[i][t+1] = it->second + arr[i];
                }
            }
        }
    }
    
    int max = 0;
    for(auto it=check[n].begin();it!=check[n].end();it++){
        if(it->second > max) max = it->second;
    }
    
    cout << max;
    
    return 0;
}
