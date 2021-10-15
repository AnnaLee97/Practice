#include <string>
#include <vector>

using namespace std;

string make(int notation, int n){
    string str= "";
    char c;
    if(n == 0) return "0";
    while(n!=0){
        if(n % notation >= 10){
            c = 'A' + n % notation - 10 ;
        } else c = n % notation +'0';
        str = c + str;
        n /= notation;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp;
    long long len = 0;
    int count = 0, tcount = 0;
    for(int i=0;tcount < t;i++){
        temp = make(n, i);
        len = temp.length();
        for(int j=0; j<len;j++){
            if(count%m == p-1){
                tcount++;
                answer += temp[j];
            }
            count++;
            if(tcount == t) break;
        }
    }
    
    
    return answer;
}
