#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<int> q;
    vector<int> temp = priorities;
    
    for(int i=0;i<priorities.size();i++){
        q.push(i);
    }
    
    sort(temp.begin(), temp.end(), greater<int>());
    
    int now = 0;
    while(!q.empty()){
        if(priorities[q.front()] == temp[now]){
            if(q.front() == location){
                break;
            }
            now++;
            q.pop();
            answer++;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    
    
    return answer;
}

-*-*-

#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    list<int> temp;
    vector<int> t;
    int i,j,flag;
    
    for(i=0;i<priorities.size();i++){
        temp.push_back(i);
    }
    
    list<int>::iterator iter;
    list<int>::iterator it;
    for(iter=temp.begin();iter!=temp.end();iter=temp.begin()){
        flag=0;
        for(it=next(iter,1);it!=temp.end();it++){
            if(priorities[(*it)] > priorities[(*iter)]){
                temp.push_back(*iter);
                temp.erase(iter);
                flag=1;
                break;
            }
        }
        if(!flag){
            t.push_back(*iter);
            temp.erase(iter);
        }
    }
    
    for(i=0;i<t.size();i++){
        if(t[i]==location){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}
