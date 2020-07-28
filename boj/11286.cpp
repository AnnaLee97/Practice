#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct compare{
    bool operator()(int &a, int &b){
        int n = a>=0 ? a : -a;
        int m = b>=0 ? b : -b;
        
        if(n==m){
            return a > b;
        }
        else return n > m;
    }
};

int main(){
    int n;
    scanf("%d\n", &n);
    priority_queue<int, vector<int>, compare> q;
    int temp;
    
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
