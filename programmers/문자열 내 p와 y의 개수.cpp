#include <string>
#include <iostream>
#include <cctype> //tolower, toupper
#include <algorithm> //transform

using namespace std;

bool solution(string s)
{
    bool answer = true;
    string temp;
    int p = 0, y=0;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='p') p++;
        else if(s[i]=='y') y++;
    }

    return p==y;
}
