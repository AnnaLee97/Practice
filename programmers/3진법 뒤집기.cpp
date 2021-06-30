#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr;
    vector<int> tmp;
    int i=1;
    
    arr.push_back(i);
    do{
        i*=3;
        arr.push_back(i);
    }while(i<=n);
    arr.pop_back();
    
    int len = arr.size();
    for(int j=len-1;j>=0;j--){
        if(n==0) break;
        
        answer += (n/arr[j])*arr[len-j-1];
        n %= arr[j];
    }
    
    
    return answer;
}
