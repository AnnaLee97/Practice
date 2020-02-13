#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = s.length();
    stack<string> st;
    for(int num=1;num < s.length();num++){
        string temp = "";
        string tmp;
        int j=0;
        int count = 0;
        for(j=0; j <= s.length()-num;j+=num){
            if(j==0){
                st.push(s.substr(j,num));
                count++;
                continue;
            }
            tmp = s.substr(j,num);
            if(tmp == st.top()){
                count++;
            }
            else {
                if(count > 1)
                    temp += to_string(count);
                temp += st.top();
                st.pop();
                st.push(tmp);
                count = 1;
            }
        }
        if (!st.empty()) {
            if (count > 1)
                temp += to_string(count);
            temp += st.top();
        }
        temp += s.substr(j);
        if(temp.length() < answer)
            answer = temp.length();
    }
    
    return answer;
}
