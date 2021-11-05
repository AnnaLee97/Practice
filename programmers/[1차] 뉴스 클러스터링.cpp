#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

#define min(a,b) (a <= b ? a : b)

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> a, b;
    int asize = 0, bsize = 0;
    string s;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i=0;i<str1.length()-1;i++){
        s = str1.substr(i, 2);
        if(s[0] < 'a' || s[0] > 'z') continue;
        if(s[1] < 'a' || s[1] > 'z') continue;
        a[s]++; asize++;
    }
    for(int i=0;i<str2.length()-1;i++){
        s = str2.substr(i, 2);
        if(s[0] < 'a' || s[0] > 'z') continue;
        if(s[1] < 'a' || s[1] > 'z') continue;
        b[s]++; bsize++;
    }
    
    double val = 0;
    for(auto it=a.begin();it!=a.end();it++){
        if(b.find(it->first) != b.end()){
            val += min(it->second, b[it->first]);
        }
    }
    
    if(asize + bsize == 0) answer = 65536;
    else answer = val * 65536 / (asize + bsize - val);
    
    return answer;
}
