#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


void make(string order, int len, string temp, int now, map<string, int> &m){
    if(temp.length() == len){
        m[temp]++;
        return;
    }
    
    for(int i = now+1; i<order.length();i++){
        make(order, len, temp+order[i], i, m);
    }
    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<map<string, int>> m(course.size());
    string temp;
    for(int i=0;i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j=0;j<course.size();j++){
            for(int k=0;k<orders[i].length();k++){
                temp = orders[i][k];
                make(orders[i], course[j], temp, k, m[j]);
            }
        }
    }
    int max;
    for(int i=0;i<course.size();i++){
        max = 2;
        
        for(auto it=m[i].begin();it!=m[i].end();it++){
            if(it->second > max){
                max = it->second;
            }
        }
        
        for(auto it=m[i].begin();it!=m[i].end();it++){
            if(it->second == max){
                answer.push_back(it->first);
            }
        }        
    }
    
    sort(answer.begin(), answer.end());
    
    

    
    return answer;
}
