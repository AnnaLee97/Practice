#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <unordered_map>


using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> m;
    string s;
    
    if(cacheSize == 0) return 5*(int)cities.size();
    
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        if(m.find(cities[i]) != m.end()){
            m[cities[i]] = i;
            answer += 1;
        }
        else if(m.size() < cacheSize){
            m[cities[i]] = i;
            answer += 5;
        }
        else {
            vector<pair<string, int>> v(m.begin(), m.end());
            sort(v.begin(), v.end(), compare);
            m.erase(v[0].first);
            m[cities[i]] = i;
            answer += 5;
        }
    }
    
    
    return answer;
}
