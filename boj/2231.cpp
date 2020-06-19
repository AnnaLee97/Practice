#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,i;
    int res=0;
    
    scanf("%d", &n);
    
    for(i=1;i<n;i++){
        int temp = i;
        int j = i;
        while(j > 0){
            temp += j%10;
            j /= 10;
        }
        if(temp == n){
            res = i;
            break;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
