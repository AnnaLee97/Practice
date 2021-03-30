#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> check(26,-1);
    
    for(int i=0;i<skill.length();i++){
        check[skill[i]-'A'] = i;
    }
    
    int now, flag;
    string temp;
    for(int i=0;i<skill_trees.size();i++){
        now = 0; flag = 0;
        temp = skill_trees[i];
        for(int j=0; j<temp.length();j++){
            if(check[temp[j]-'A'] >= 0) {
                if(now == check[temp[j]-'A']){
                    now++;
                }
                else {
                    flag = 1; break;
                }
            }
        }
        if(!flag) answer++;
    }
    
    return answer;
}
