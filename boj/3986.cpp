#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    string str;
    int i;
    int result = 0;
    
    cin >> n;
    for(i=0; i<n; i++){
        stack<char> st;
        cin >> str;
        for(int j=0; j< str.length(); j++){
            if(!st.empty() && st.top() == str[j]){
                st.pop();
                continue;
            }
            st.push(str[j]);
        }
        if(st.empty())
            result++;
    }
    cout << result << endl;
    return 0;
}
