#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    map<int, int> mine;
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        if(mine.find(temp) == mine.end()){
            mine[temp]=1;
        }
        else mine[temp]++;
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &temp);
        if(mine.find(temp) == mine.end()){
            printf("0");
        }
        else printf("%d", mine[temp]);
        if(i==m-1)
            printf("\n");
        else printf(" ");
    }
    
    return 0;
}
