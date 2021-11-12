#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int now;
    
    for(now = 0; now < land.size()-1; now++){
        vector<int> temp(land[now].begin(), land[now].end());
        sort(temp.begin(), temp.end(), greater<int>());
        
        for(int i=0;i<land[now+1].size();i++){
            if(land[now][i] == temp[0]){
                land[now+1][i] += temp[1];
            }
            else {
                land[now+1][i] += temp[0];
            }
        }
    }
    
    auto it = max_element(land[land.size()-1].begin(), land[land.size()-1].end());
    answer = (*it);
    

    return answer;
}
