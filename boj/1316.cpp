#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    int num=0;
    int flag;
    for(int i=0;i<n;i++){
        cin >> str;
        flag =0;
        map<char, int> m;
        for(int j=0;j<str.length();j++){
            if(m.find(str[j])==m.end()){
                m[str[j]]=0;
            }
            else{
                if(str[j]!=str[j-1]){
                    flag =1;
                    break;
                }
            }
        }
        if(!flag) num++;
    }
    
    cout << num <<"\n";
    
    return 0;
}
