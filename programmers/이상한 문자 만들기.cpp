#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int len=0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            len = 0;
            answer.push_back(s[i]);
        }else {
            if(len%2==0){
                answer.push_back(toupper(s[i]));
            } else {
                answer.push_back(tolower(s[i]));
            }
            len++;
        }
    }
    return answer;
}
