#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match = 0;
    int zero = 0;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int j=0;
    for(int i=0;i<6;i++){
        if(!lottos[i]){
            zero++;
            continue;
        }
        for(j;j<6;j++){
            if(win_nums[j] == lottos[i]){
                match++;
                j++; break;
            }
            else if(win_nums[j] > lottos[i]){
                break;
            }
        }
        
    }

    
    if(match+zero == 0){
        answer.push_back(6);
    }
    else {
        answer.push_back(7-match-zero);
    }
    
    if(match == 0){
        answer.push_back(6);
    }
    else {
        answer.push_back(7-match);
    }
    
    return answer;
}
