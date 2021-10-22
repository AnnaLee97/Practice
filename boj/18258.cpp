#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int temp;
    string cmd;
    queue<int> q;
    
    for(int i=0;i<n;i++){
        cin >> cmd;
        
        if(cmd == "push"){
            cin >> temp;
            q.push(temp);
        } else if(cmd == "front"){
            if(q.empty()) cout << -1<< "\n";
            else cout << q.front()<< "\n";
        } else if(cmd == "back"){
            if(q.empty()) cout << -1<< "\n";
            else cout << q.back()<< "\n";
        } else if(cmd == "size"){
            cout << q.size()<< "\n";
        } else if(cmd == "pop"){
            if(q.empty()) cout << -1<< "\n";
            else {
                cout << q.front()<< "\n";
                q.pop();
            }
        } else if(cmd == "empty"){
            if(q.empty()) cout << 1<< "\n";
            else cout << 0<< "\n";
        }
    }
    
    return 0;
}
