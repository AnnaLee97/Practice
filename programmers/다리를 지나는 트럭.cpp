#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int ind = 0;
    int n = truck_weights.size();
    int total = 0;
    queue<pair<int, int>> q;
    
    
    for(answer = 1;;answer++){
        if(!q.empty() && answer - q.front().second == bridge_length){
            total -= truck_weights[q.front().first];
            q.pop();
        }
        
        if(q.size() < bridge_length && ind < n && total+truck_weights[ind] <= weight){
            q.push(make_pair(ind, answer));
            total += truck_weights[ind++];
        }
        
        if(ind >= n && q.empty()) break;
    }
    
    
    
    return answer;
}
