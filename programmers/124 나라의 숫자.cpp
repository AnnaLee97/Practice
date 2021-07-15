#include <string>
#include <algorithm>

using namespace std;


string solution(int n) {
    string answer = "";
    int number[3] = {4,1,2};
    
    int a;
    
    while(n!=0){
        a = n%3;
        answer += number[a]+'0';
        n /=3;
        if(n && a == 0){
            n--;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
