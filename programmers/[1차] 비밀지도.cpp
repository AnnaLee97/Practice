#include <string>
#include <vector>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    bitset<16> temp;
    string s;
    for(int i=0;i<n;i++){
        s = "";
        bitset<16> a(arr1[i]);
        bitset<16> b(arr2[i]);
        temp = a | b;
        
        for(int j=n-1; j>=0; j--){
            if(temp[j]){
                s += "#";
            } else s += " ";
        }
        answer.push_back(s);
    }
    
    return answer;
}
