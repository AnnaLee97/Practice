#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    int now;
    stack<int> st;
    vector<int> ans(n, -1);
    vector<int> arr;
    
    for(int i=0;i<n;i++){
        cin >> now;
        arr.push_back(now);
        while(!st.empty() && arr[st.top()] < now){
            ans[st.top()] = now;
            st.pop();
        }
        st.push(i);
    }
    
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i!=n-1)
            cout <<" ";
    }
    return 0;
}
