#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> inyong(100001, 0);
    
    for(int i=0;i<citations.size();i++){
        inyong[citations[i]]++;
    }
    
    for(int i=inyong.size()-2; i>=0;i--){
        inyong[i] += inyong[i+1];
        if(inyong[i] >= i){
            answer = i;
            break;
        }
        
    }
    
    return answer;
}
