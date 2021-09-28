#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    
    int start=0, end=0;
    int sum = 0;
    while(start != n){
        if(sum <= n){
            if(sum < n && end == n) break;
            if(sum == n){
                answer++;
                if(end == n) break;
            }
            sum += arr[end];
            end++;
            
        } else {
            sum -= arr[start];
            start++;
        }
    }
    
    
    return answer;
}
