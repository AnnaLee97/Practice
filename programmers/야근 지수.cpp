#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;  
    
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    int i=0;
    int temp, t, top;
    
    while(!pq.empty() && i<=n){
        temp = pq.top();
        pq.pop();
        
        if(temp <= 0) break;
        
        if(pq.empty()) top = 0;
        else top = pq.top();
        
        t = temp - top +1;
        
        if(i+t >= n){
            pq.push(temp-(n-i));
            break;
        }
        pq.push(top-1);
        i += t;
    }
    
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        if(temp <= 0) break;
        
        answer += (long long)temp * temp;
    }
    
    return answer;
}
