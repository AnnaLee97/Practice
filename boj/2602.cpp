#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void find(vector<vector<int>> arr, vector<int> &visit, int now, int &count){
    if(visit[now]) return;
    count++;
    visit[now]++;
    
    if(arr[now].empty()) return;
    for(int i=0;i<arr[now].size();i++){
        find(arr,visit, arr[now][i], count);
    }
    return;
}

int main(){
    int n,t;
    scanf("%d", &n);
    scanf("%d", &t);
    vector<vector<int>> arr(n+1);
    int le,ri;
    for(int i=0;i<t;i++){
        scanf("%d %d", &le, &ri);
        arr[le].push_back(ri);
        arr[ri].push_back(le);
    }
    int count =0;
    vector<int> visit(n+1, 0);
    visit[1]=1;
    for(int i=0;i<arr[1].size();i++){
         find(arr, visit, arr[1][i], count);
    }
   
    printf("%d\n", count);
    return 0;
}
