#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, int>> temp;
    vector<pair<int, double>> cal;
    
    sort(stages.begin(), stages.end(), greater<int>());
    
    int now = N+1;
    int count = 0;
    for(int i=0; i<stages.size(); i++){
        if(now != stages[i]){
            temp.push_back(make_pair(now, count));
            count = 0;
            for(--now;now > stages[i];now--){
                temp.push_back(make_pair(now, count));
            }
        }
        
        count++;
    }
    temp.push_back(make_pair(now, count));
    count = 0;
    for(--now;now>0;now--){
        temp.push_back(make_pair(now, count));
    }
    double val;
    now = temp[0].second;
    for(int i=1; i<temp.size(); i++){
        val = 0;
        if(now + temp[i].second != 0){
            val = (double)temp[i].second/(now + temp[i].second);
        }
        cal.push_back(make_pair(temp[i].first, val));
        now += temp[i].second;
        
    }
    
    sort(cal.begin(), cal.end(), compare);
    for(int i=0;i<cal.size();i++){
        answer.push_back(cal[i].first);
    }
    
    return answer;
}
