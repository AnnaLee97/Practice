#include <iostream>
#include <vector>

using namespace std;

void divi(int &a, int&b){
    int m = min(a,b);
    int i=2;
    while(m!=1 && i<= m){
        if(a%i ==0 && b%i ==0){
            a /= i;
            b /= i;
            m = min(a,b);
        }
        else{
            i++;
        }
    }
    return;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int a, b, temp;
    cin >> temp;
    for(int i=1; i<n;i++){
        a = temp;
        cin >> b;
        divi(a, b);
        cout << a <<"/"<<b<<"\n";
    }
    return 0;
}
