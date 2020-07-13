#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    char tmp[51];
    string str;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        stack<char> st;
        scanf("%s", tmp);
        str = (string)tmp;
        for(int j=0;j<str.length(); j++){
            if(st.empty()){
                st.push(str[j]);
            }
            else{
                if(st.top() == '(' && str[j]==')'){
                    st.pop();
                }
                else st.push(str[j]);
            }
        }
        if(st.empty()) printf("YES\n");
        else printf("NO\n");
    }
    
    
    return 0;
}
