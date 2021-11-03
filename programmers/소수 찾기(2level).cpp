#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>

using namespace std;

map<string, int> dic;

void dfs(set<int> &s, string numbers, string str, bitset<7> check, int now){
    int temp;
    
    check[now] = true;
    str += numbers[now];
    if(dic.find(str) != dic.end()){
        return;
    }
    
    dic[str]++;
    temp = stoi(str);
    if(temp > 1 && s.find(temp) == s.end()){
        bool flag = false;
        for(int i=2;i<(int)sqrt(temp)+1;i++){
            if(temp % i == 0){
                flag = true; break;
            }
        }
        
        if(!flag){
            s.insert(temp);    
        }
    }
    
    for(int i=0;i<numbers.length();i++){
        if(!check[i]){
            dfs(s, numbers, str, check, i);
        }
    }
    
    return;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    bitset<7> check(false);
    
    
    for(int i=0;i<numbers.length();i++){
        dfs(s, numbers, "", check, i);
    }
    
    answer = s.size();
    
    return answer;
}
