#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool check(char c){
    if(c >= 'a' and c <= 'z') return true;
    if(c >= 'A' and c <= 'Z') return true;
    return false;
}
/*
char to_upper(char c){ //cctype 헤더에 구현되어 있음
    if(c >= 'a' and c <= 'z') return (c-32);
    return c;
}
*/
string solution(string s) {
    string answer = "";
    bool flag = true;
    char c;
    
    for(int i=0; i<s.length(); i++){
        c = s[i];
        if(flag){
            if(check(s[i])){
                c = toupper(c);
            }
            answer += c;
            flag = false;
        } else {
            if(check(s[i])){
                c = tolower(c);
            }
            answer += c;
        }
        if(c == ' ') flag = true;
    }
    
    return answer;
}
