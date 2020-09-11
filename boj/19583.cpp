#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string s,e,q;
    string tim, name;
    cin >> s >> e >> q;
    map<string, int> m;
    int num=0;
    
    do{
        cin >> tim >> name;
        if(tim <=s){
            m[name]=0;
        }
        else if(tim >= e && tim <= q){
            if(m.find(name)==m.end()){
                continue;
            }
            else{
                m[name]++;
                if(m[name]==1) num++;
            }
        }
        
    }while(getc(stdin)=='\n');
    
    cout << num <<"\n";
    
    return 0;
}
