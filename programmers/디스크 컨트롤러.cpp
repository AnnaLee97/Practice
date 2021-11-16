#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

vector<pair<int, int>> heap(1, {-1, -1});
void print();

void insert(int start, int end){
    pair<int, int> temp;
    int ind = heap.size();
    
    heap.push_back(make_pair(start, end));
    while(ind > 1 && heap[ind/2].second >= heap[ind].second){
        if(heap[ind/2].second == heap[ind].second && heap[ind/2].first < heap[ind].first) break;
        temp = heap[ind/2];
        heap[ind/2] = heap[ind];
        heap[ind] = temp;
        ind /= 2;
    }
    //print();
    return;
}

void print(){
    for(int i=1;i<heap.size();i++){
        cout << heap[i].first <<"," << heap[i].second<< "/";
    }
    cout <<"\n";
}

void pop(){
    if(heap.size() <= 1 )return;

    heap[1] = heap[heap.size()-1];
    heap.pop_back();
    
    if(heap.size() <= 2){
        return;
    }
    
    int now = 1;
    int temp;
    pair<int, int> tmp;
    
    while((now*2 < (int)heap.size()) && (heap[now*2].second <= heap[now].second || (now*2 + 1 < heap.size() && heap[now*2 + 1].second <= heap[now].second))){
        temp = now*2;
        if(now*2 + 1 < heap.size() && heap[now*2 + 1].second <= heap[now].second){
            if(heap[now*2].second == heap[now*2 + 1].second){
                temp = heap[now*2].first < heap[now*2 + 1].first ? now*2 : now*2 + 1;
            }
            else if(heap[now*2].second > heap[now*2 + 1].second){
                temp = now*2 + 1;
            }
        }
        
        tmp = heap[now];
        heap[now] = heap[temp];
        heap[temp] = tmp;
        now = temp;
    }
    //print();

    return;
}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    long long avg = 0;
    int count = 0;
    int now = 0;
    vector<vector<int>> dic(1001);
    
    for(int i=0;i<jobs.size();i++){
        dic[jobs[i][0]].push_back(jobs[i][1]);
    }
    
    for(int i=0; true; i++){
        if(now > 0) now--;
        
        if(i<dic.size()){
            for(int j=0;j<dic[i].size();j++){
                insert(i, dic[i][j]);
            }
        }
        
        if(heap.size() > 1 && now == 0){
            avg += heap[1].second + i - heap[1].first;
            now = heap[1].second;
            
            count++;
            pop();
        }
        
        
        if(count == jobs.size()) break;
    }
    
    answer = avg / (int)jobs.size();
    
    
    return answer;
}
