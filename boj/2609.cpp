#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int mx = (n>m ? n : m);
    int i;
    for(i=mx;i>1;i--){
        if(n%i == 0 && m%i == 0){
            break;
        }
    }
    cout << i << "\n" << n / i * m << "\n";
    
    return 0;
}
