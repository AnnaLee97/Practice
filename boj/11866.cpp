#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    printf("<");
    int count=0;
    int temp;
    while(!q.empty()){
        count++;
        temp = q.front();
        q.pop();
        if(count==k){
            count = 0;
            printf("%d", temp);
            if(!q.empty()){
                printf(", ");
            }
            else printf(">\n");
        }
        else{
            q.push(temp);
        }
    }
    
    return 0;
}
