#include <string>
#include <vector>

using namespace std;

char ch[5] = {'A','E','I','O','U'};
void check(string str, string s, long long &count, int now, bool &flag){
    if(str.length()>4 || flag){
        return;
    }
    count++;
    str += ch[now];
    if(s == str){
        flag = true;
        return;
    } else {
        for(int i=0;i<5;i++){
            check(str, s, count, i, flag);
        }
    }
    return;
}

int solution(string word) {
    long long answer = 0;
    bool flag = false;
    
    for(int i=0;i<5; i++){
        check("",word, answer, i, flag);
    }
    
    return answer;
}
