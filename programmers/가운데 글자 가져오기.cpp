#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int i=0;
    int start = 0;
    
    if(s.length()%2 == 0){
        i = 2;
        start = (s.length() / 2)-1;
    }
    else {
        i = 1;
        start = s.length() / 2;
    }
    
    for(int j=0; j<i;j++){
        answer += s[start+j];
    }
    
    return answer;
}
