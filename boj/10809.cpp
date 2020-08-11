#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> arr(26,-1);
    string str;
    cin >> str;
    int temp;
    for(int i=0;i<str.length();i++){
        temp = str[i]-'a';
        if(arr[temp] == -1){
            arr[temp] = i;
        }
    }
    
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
