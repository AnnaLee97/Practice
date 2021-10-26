#include <string>
#include <vector>
#include <algorithm>


using namespace std;


void go(int &answer, int k, vector<vector<int>> dungeons, vector<bool> check, int now, int count){
    count++;
    k -= dungeons[now][1];
    check[now] = true;
    
    if(answer < count) answer = count;
    
    for(int i=0;i<dungeons.size();i++){
        if(!check[i] && k >= dungeons[i][0]){
            go(answer, k, dungeons, check, i, count);
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> check(dungeons.size(), false);
    
    for(int i=0;i<dungeons.size();i++){
        go(answer, k, dungeons, check, i, 0);
    }   
    
    
    return answer;
}
