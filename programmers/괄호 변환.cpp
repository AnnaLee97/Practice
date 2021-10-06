#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check1(string str){
    int count = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') count++;
    }
    return (count == str.length()-count ? true : false);
}

bool check2(string str){
    stack<char> st;
    if(str.length()==0) return true;
    st.push(str[0]);
    for(int i=1;i<str.length();i++){
        if(st.top()=='(' && str[i] == ')') st.pop();
        else st.push(str[i]);
    }
    return (st.size()==0 ? true : false);
}

string reverse(string s){
    string ret = "";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') ret += ')';
        else ret += '(';
    }
    return ret;
}

string make(string s){
    string res = "";
    
    if(s =="") return res;
    
    string u,v;
    
    for(int i=2;i<=s.length();i+=2){
        u = s.substr(0,i);
        if(i == s.length()) v = "";
        else v = s.substr(i);
        if(check1(u)){
            if(check2(u)){
                return u + make(v);
            } else {
                res += '(';
                res += make(v);
                res += ')';
                u = u.substr(1, u.length()-2);
                res += reverse(u);
                return res;
            }
            break;
        }
    }
    return res;
}

string solution(string p) {
    string answer = "";
    
    answer = make(p);
    
    return answer;
}
