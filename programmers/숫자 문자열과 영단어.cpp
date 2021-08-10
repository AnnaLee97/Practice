#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string::size_type ind;
    vector<string> numb = {"zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine"};
    
    for(int i=0;i<numb.size();i++){
        ind = s.find(numb[i]);
        while(ind != string::npos){
            s = s.substr(0, ind) + (char)(i+'0') + s.substr(ind+numb[i].length());
            //s.replace(ind, ind+numb[i].length(), (char)(i+'0'));
            ind = s.find(numb[i]);
        }
    }
    
    for(int i=0;i<s.length();i++){
        answer = answer*10 + (int)(s[i]-'0');
    }
    
    return answer;
}
