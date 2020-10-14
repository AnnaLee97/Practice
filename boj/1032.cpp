#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    string temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        arr[i] = temp;
    }
    string ans = "";
    int flag = 0;
    for(int j=0;j<arr[0].length();j++){
        flag = 0;
        for(int i=1;i<n;i++){
            if(arr[i][j] != arr[0][j]){
                flag = 1;
                break;
            }
        }
        if(flag){
            ans +="?";
        }
        else ans+=arr[0][j];
    }
    cout << ans <<"\n";
    
    return 0;
}
