#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string score="", bonus, option;
    vector<int> sc(4, 0);
    int now = 0;
    bool flag = false;
    
    for(int i=0;i<dartResult.length();i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(!flag){
                flag = true;
                now++;
            }
            score += dartResult[i];
        } else if(dartResult[i] >='A' && dartResult[i]<='Z'){
            flag = false;
            sc[now] = stoi(score);
            score = "";
            if(dartResult[i] == 'D') sc[now] = pow(sc[now], 2);
            else if(dartResult[i] == 'T') sc[now] = pow(sc[now], 3);
        } else {
            if(dartResult[i]=='*'){
                sc[now] *= 2;
                sc[now-1] *= 2;
            } else {
                sc[now] *= -1;
            }
        }
    }
    
    for(int i=0;i<4;i++){
        answer += sc[i];
    }
    
    return answer;
}
