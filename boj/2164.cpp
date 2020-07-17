#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    queue<int> q;
    int temp;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    bool flag = true;
    while(q.size()!=1){
        if(flag){
            q.pop();
        }
        else{
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        flag = !flag;
    }
    printf("%d\n", q.front());
    return 0;
}
