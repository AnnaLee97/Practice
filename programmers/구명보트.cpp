#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i=0, j=people.size()-1, count=0;
    sort(people.begin(), people.end(), greater<int>());
    vector<bool> flags(people.size(), false);
    
    while(count < people.size()){
        for(j;j>i;j--){
            if(!flags[j] && people[j]+people[i] <= limit){
                flags[j] = true;
                count++;
                break;
            } else if(people[j]+people[i] > limit) break;
        }
        flags[i++] = true;
        answer++; count++;
    }
    
    return answer;
}
