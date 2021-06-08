#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string a, b;
    string ans="";
    int temp=0;
    
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int j=0;
    int temp=0;
    for(int i=0;i<a.length();i++){
        if(j<b.length()){
            temp += (a[i]-'0') + (b[j]-'0');
            j++;
        }
        else{
            temp += (a[i]-'0');     
        }
        ans += (temp%10) + '0';
        temp /= 10;
    }
    for(j;j<b.length();j++){
        temp += (b[j]-'0');
        ans += (temp%10) + '0';
        temp /= 10;
    }
    while(temp != 0){
        ans += (temp%10) + '0';
        temp /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    
    return 0;
}
