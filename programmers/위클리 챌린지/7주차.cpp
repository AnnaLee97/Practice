#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size(),0);
    set<int> s;
    int i=0, j=0;

    while(j<leave.size()){
        if(s.find(leave[j]) == s.end()){
            answer[enter[i]-1] += s.size();
            
            for(auto it = s.begin(); it != s.end(); it++){
                answer[(*it)-1]++;
            }  
            s.insert(enter[i]);
            i++;
        } else {
            s.erase(leave[j]);
            j++;
        }
    }
    
    return answer;
}
