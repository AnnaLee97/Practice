#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        int n, m;
        cin >> n >> m;
        
        vector<int> pri(n);
        queue<pair<int, int>> q;
        
        for(int j=0;j<n;j++){
            cin >> pri[j];
            q.push(make_pair(j,pri[j]));
        }
        
        sort(pri.begin(), pri.end(), greater<int>());
        int now = 0;
        
        pair<int, int> temp;
        while(1){
            if(q.front().second < pri[now]){
                temp = q.front();
                q.pop();
                q.push(temp);
            }
            else{
                if(q.front().first == m){
                    cout << ++now << "\n";
                    break;
                }
                else{
                    q.pop();
                    now++;
                }
            }
        }
        
    }
    
    return 0;
}
