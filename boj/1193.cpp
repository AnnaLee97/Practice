#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;

    int n=0, temp=0,i=0;
    for(i=0;i<=x;i++){
        temp = i*(i+1)/2;
        if(temp >= x){
            break;
        }
        else{
            n = i;
        }
    }

    temp -= i;
    
    int t = x-temp;
    if(n%2 ==0){
        cout << n+2-t << '/' << t <<"\n";
    }
    else{
        cout << t << '/' << n+2-t <<"\n";
    }
    
    return 0;
}
