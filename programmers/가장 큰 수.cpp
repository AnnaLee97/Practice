#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    
    for(int i=0;i<numbers.size();i++){   
        str.push_back(to_string(numbers[i]));
    }
    
    sort(str.begin(), str.end(), compare);
    
    
    bool flag = true;
    for(int i=0;i<str.size();i++){
        if(flag && stoi(str[i]) != 0)
            flag = false;
        answer += str[i];
    }
    
    if(flag) answer = "0";
    
    return answer;
}
