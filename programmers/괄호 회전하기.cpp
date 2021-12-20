#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ssang(char a, char b){
    bool ret = false;
    if(a == '[' && b == ']') ret = true;
    if(a == '(' && b == ')') ret = true;
    if(a == '{' && b == '}') ret = true;
    return ret;
}


bool isright(string s){
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        if(st.empty() || !ssang(st.top(), s[i])) st.push(s[i]);
        else st.pop();
    }
    
    if(st.empty()) return true;
    else return false;
}

string move(string s, int i){
    string ret = s.substr(i) + s.substr(0, i);
    return ret;
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.length();i++){
        if(isright(move(s, i))) answer++;
    }
    
    return answer;
}
