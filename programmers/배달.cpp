#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    queue<pair<int, int>> towns;
    vector<int> times(N+1, 1000000);
    vector<vector<pair<int, int>>> arr(N+1);
    
    towns.push(make_pair(1,0));
    times[1] = 0;
    int now, time;
    
    for(int i=0;i<road.size();i++){
        arr[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        arr[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    } 
    
    while(!towns.empty()){
        now = towns.front().first;
        time = towns.front().second;
        towns.pop();
        
        for(int i=0;i<arr[now].size();i++){
            if(arr[now][i].second + time < times[arr[now][i].first]){
                towns.push(make_pair(arr[now][i].first, arr[now][i].second + time));
                times[arr[now][i].first] = arr[now][i].second + time;
            }
        }
    }
    
    for(int i=1;i<times.size();i++){
        if(times[i] <= K) answer++;
    }


    return answer;
}
