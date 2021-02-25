#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    
    int num = 0;
    char c = ' ';
    
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            if(c != ' '){
                num++; c = ' ';
            }
        }
        else if(str[i] != ' '){
            c = str[i];
        }
    }
    if(c != ' ')
        num++;
    
    cout << num <<"\n";
}
