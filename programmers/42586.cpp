#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> st;
    int num;
    for(int i=0;i<progresses.size();i++){
        int t = ((100-progresses[i])%speeds[i]==0 ? (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i]+1);
        if(st.empty()){
            st.push(t);
            num = 1;
        }
        else if(t <= st.top()){
            num++;
        }
        else {
            answer.push_back(num);
            st.pop();
            st.push(t);
            num = 1;
        }
    }
    answer.push_back(num);
    
    return answer;
}
