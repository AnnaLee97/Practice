#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> m;
    
    for(long long i=0;i<room_number.size();i++){
        if(m.find(room_number[i]) == m.end()){
            m[room_number[i]] = room_number[i]+1;
            answer.push_back(room_number[i]);
        }
        else {
            long long j = m[room_number[i]];
            while(j<=k){
                if(m.find(j) == m.end()){
                    m[j] = j+1;
                    m[m[room_number[i]]] = j+1;
                    m[room_number[i]] = j+1;
                    answer.push_back(j);
                    break;
                }
                else {
                    j = m[j];
                }
            }    
        }
    }
    
    return answer;
}
