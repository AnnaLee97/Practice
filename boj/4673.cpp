#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    vector<bool> arr(10001, true);
    
    int temp, j;
    for(int i=1;i<=10000;i++){
        j=i; temp = j;
        while(j!=0){
            temp += j%10;
            j/=10;
        }
        if(temp <= 10000){
            arr[temp] = false;
        }
    }
    
    for(int i=1;i<=10000;i++){
        if(arr[i]){
            printf("%d\n", i);
        }
    }
    
    
    return 0;
}
