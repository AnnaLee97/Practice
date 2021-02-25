#include <iostream>

using namespace std;

int main(){
    int a, b;
    
    cin >> a >> b;
    
    int c=0, d=0;
    for(int i=0;i<3;i++){
        c = 10*c + a%10;
        d = 10*d + b%10;
        a/=10; b/=10;
    }
    
    cout << (c >d ? c : d) << "\n";
    
}
