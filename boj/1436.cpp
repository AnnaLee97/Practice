#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    int num=0;
    scanf("%d", &n);
    
    int i=666, j;
    int temp = 0;
    while(num != n){
        temp = 0;
        j = i;
        while(j!=0){
            if(j%10 == 6){
                temp++;
            }
            else{
                temp = 0;
            }
            if(temp == 3){
                num++;
                break;
            }
            j /= 10;
        }
        i++;
    }
    
    printf("%d\n", i-1);
    
    return 0;
}
