#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t, line;
    string temp;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> line;
        map<string, int> m;
        for(int j=0;j<line;j++){
            cin >> temp;
            cin >> temp;
            if(m.find(temp)==m.end()){
                m[temp]=1;
            }
            else m[temp]++;
        }
        long long sum=1;
        map<string, int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            sum *= (it->second) +1 ;
        }
        cout << sum-1 << "\n";
    }
    
    return 0;
}
