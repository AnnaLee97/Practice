#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    string str;
    bool flag;
    getline(cin, str);
    while(str!="."){
        stack<char> st;
        

        flag = false;
        for(int i=0;i<str.length();i++){
            if(str[i]=='(' || str[i]=='['){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                if(st.empty() || st.top()!='('){
                    flag = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            else if(str[i]==']'){
                if(st.empty() || st.top()!='['){
                    flag = true;
                    break;
                }
                else st.pop();
            }
        }
        if(!st.empty()) flag=true;
        if(flag){
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
        getline(cin, str);
    }
    
    return 0;
}
