#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int size = scoville.size();
    map<int, int> dic;
    
    for(int i=0;i<scoville.size();i++){
        dic[scoville[i]]++;
    }
    
    long long temp;
    while(size > 1){
        auto it = dic.begin();
        temp = it->first;
        
        if(temp >= K) break;
        
        if(it->second > 2) {
            it -> second -= 2;
            temp += 2 * (it->first);
        } else if(it -> second == 2){
            temp += 2 * (it->first);
            dic.erase(it);
        } else {
            auto tempit = it;
            temp += (long long)2 * ((++it)->first);
            dic.erase(tempit);
            if(it->second > 1) {
                it -> second -= 1;
            } else {
                dic.erase(it);
            }
        }

        dic[temp]++;
        answer++;
        size--;
    }
    
    if((dic.begin())->first < K){
        answer = -1;
    }
    
    return answer;
}
