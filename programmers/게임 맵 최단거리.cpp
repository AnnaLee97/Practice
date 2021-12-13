#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

void bfs(vector<vector<int>> maps, int &ans){
    queue<pair<int, pair<int, int>>> q;
    int n = maps.size();
    int m = maps[0].size();
    
    int dist = 1;
    vector<vector<int>> check(n, vector<int>(m, 100001));
    q.push(make_pair(dist, make_pair(0, 0)));
    
    int row, col;
    while(!q.empty()){
        dist = q.front().first;
        row = q.front().second.first;
        col = q.front().second.second;
        q.pop();
        
        if(check[row][col] <= dist) continue;
        
        check[row][col] = dist;
        
        if(row == n-1 && col == m-1) {
            ans = dist;
            continue;
        }
        
        if(row + 1 < n && maps[row+1][col] == 1 && check[row+1][col] > dist+1){
            q.push(make_pair(dist+1, make_pair(row+1, col)));
        }
        if(col + 1 < m && maps[row][col+1] == 1 && check[row][col+1] > dist+1){
            q.push(make_pair(dist+1, make_pair(row, col+1)));
        }
        if(row - 1 >= 0 && maps[row-1][col] == 1 && check[row-1][col] > dist+1){
            q.push(make_pair(dist+1, make_pair(row-1, col)));
        }
        if(col - 1 >= 0 && maps[row][col-1] == 1 && check[row][col-1] > dist+1){
            q.push(make_pair(dist+1, make_pair(row, col-1)));
        }
    }
    
    return;
}

int solution(vector<vector<int>> maps)
{
    int answer = 10001;
    
    bfs(maps, answer);
    
    if(answer == 10001) answer = -1;
    
    return answer;
}
