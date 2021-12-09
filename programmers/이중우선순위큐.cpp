#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    multiset<int> s;
    
    string str, tok;
    for(int i=0;i<operations.size();i++){
        istringstream ss(operations[i]);
        ss >> str >> tok;
        
        if(str == "I"){
            s.insert(stoi(tok));
        }
        else if(tok == "1"){
            if(!s.empty()){
                auto it = prev(s.end());
                s.erase(it);
            }
        }
        else {
            if(!s.empty()){
                auto it = s.begin();
                s.erase(it);
            }
        }
    }
    
    if(!s.empty()){
        answer[1] = *(s.begin());
        answer[0] = *(prev(s.end()));
    }
    
    return answer;
}
