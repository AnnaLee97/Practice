#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> temp(s.length());
    for(int i=0;i<s.length();i++){
        temp[i] = (int)s[i];
    }
    if(s.length()>1)
        sort(temp.begin(), temp.end(), greater<int>());
    
    for(int i=0;i<s.length();i++){
        answer += (char)temp[i];
    }
    
    return answer;
}

/*
//You can use sort for string!
sort(s.begin(), s.end(), greater<char>());
*/
