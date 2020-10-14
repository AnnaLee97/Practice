#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> m;
    m["push"]=0;
    m["pop"]=1;
    m["size"]=2;
    m["empty"]=3;
    m["top"]=4;
    
    stack<int> st;
    string temp;
    int t;
    for(int i=0;i<n;i++){
        cin >> temp;
        switch(m[temp]){
            case 0 : cin >> t;
                    st.push(t);
                break;
            case 1: if(st.size()==0) cout << "-1\n";
                    else {t = st.top(); cout << t << "\n"; st.pop();}
                break;
            case 2: cout << st.size() << "\n"; break;
            case 3: if(st.empty()){
                cout << "1\n";
            }
                else cout << "0\n";
                break;
            case 4: if(st.size()==0) cout << "-1\n";
                    else cout << st.top() << "\n";
                    break;
        }
    }
    
    return 0;
}
