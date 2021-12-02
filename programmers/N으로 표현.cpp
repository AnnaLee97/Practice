#include <string>
#include <vector>
#include <map>

using namespace std;

vector<map<int, int>> dic(9);

void dp(int ind, int &answer, int n, int number){
    string s="";
    
    for(int i=0;i<ind;i++){
        s += to_string(n);
    }
    
    dic[ind][stoi(s)] = 1;
    
    for(int i=1;i<=ind/2;i++){
        for(auto it=dic[i].begin();it!=dic[i].end();it++){
            for(auto itt=dic[ind-i].begin();itt!=dic[ind-i].end();itt++){
                dic[ind][(it->first) * (itt->first)] = 1;
                dic[ind][(it->first) + (itt->first)] = 1;
                dic[ind][(it->first) - (itt->first)] = 1;
                dic[ind][(itt->first) - (it->first)] = 1;
                if((it->first) != 0) dic[ind][(itt->first) / (it->first)] = 1;
                if((itt->first) != 0) dic[ind][(it->first) / (itt->first)] = 1;
                
                
                if(dic[ind].find(number) != dic[ind].end()){
                    answer = ind;
                    return;
                }
            }
        }
    }
    
    return;
}

int solution(int n, int number) {
    int answer = -1;
    
    if(n == number) return 1;
    
    for(int i=1;i<=8;i++){
        dp(i, answer, n, number);
        if(answer != -1) break;
    }
    
    
    return answer;
}
