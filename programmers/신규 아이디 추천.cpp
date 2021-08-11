#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool check(char c){
    bool ret=false;
    if(c>='a' && c <='z') ret = true;
    if(c>='0' && c <='9') ret = true;
    if(c=='_'||c=='-') ret = true;
    
    return ret;
}

string solution(string new_id) {
    string result = "";
    char c;
    bool flag=false;
    int len;
    
    
    for(int i=0; i<new_id.length(); i++){
        c = tolower(new_id[i]);
        flag=false;
        if(c=='.'){
            if(i && i!=new_id.length()-1){
                if(result.length()!=0 && result[result.length()-1] !='.'){
                    flag = true;
                }
            }
        }
        else if(check(c)) flag = true;
        
        if(flag){
            result += c;
        }
    }
    
    if(result.length() == 0){
        result = "a";
    }
    
    for(len = result.length()-1; len >= 0 ; len--){
        if(result[len]!='.'){
            break;
        }
    }
    result = result.substr(0, len+1);
    
    len = result.length();
    if(len >= 16){
        if(result[14]=='.') result = result.substr(0,14);
        else result = result.substr(0,15);
    }
    
    if(len < 3){
        for(int i=len;i<3;i++){
            result += result[len-1];
        }
    }
    
    return result;
}
