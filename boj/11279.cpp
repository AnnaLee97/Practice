#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int temp;
    scanf("%d\n", &n);
    priority_queue<int, vector<int>, less<int>> q;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        if(temp){
            q.push(temp);
        }
        else{
            if(q.empty()){
                printf("0\n");
                continue;
            }
            printf("%d\n", q.top());
            q.pop();
        }
    }
    
    return 0;
}
