#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


void factorial(int n, long long k, vector<long long> &temp){
    long long val = 1;
    
    for(int i=1; i<n ;i++){
        val *= i;
        temp[n-i-1] = val;
    }
    return;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> temp(n, 1);
    map<int, bool> check;
    long long t;
    int count;
    
    factorial(n, k, temp);
    
    for(int i=1;i<=n;i++){
        check[i] = true;
    }
    
    k = k-1;
    
    map<int, bool> ::iterator it;
    for(int i=0;i<n;i++){
        count = 0;
        t = k / temp[i];
        it = check.begin();
        for(it;it!=check.end();it++){
            if(count++ == t) break;
        }
        
        answer.push_back(it->first);
        check.erase(answer[i]);
        k = k % temp[i];
    }
    
    return answer;
}
