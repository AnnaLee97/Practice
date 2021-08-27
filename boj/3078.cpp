#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    vector<int> arr(21, 0);
    long long count=0;
    int n, k;
    string temp;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        if(q.size()==k+1){
            arr[q.front()]--;
            q.pop();
        }
        cin >> temp;
        count += arr[temp.length()];
        arr[temp.length()]++;
        q.push(temp.length());
    }
    
    cout << count;
    
    
    
    return 0;
}
