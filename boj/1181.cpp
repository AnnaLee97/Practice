#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string s, string d){
    if(s.length() == d.length()){
        return s < d;
    }
    else {
        return s.length() < d.length();
    }
}


int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), compare);
    string temp;
    for(int i=0;i<n;i++){
        if(i==0){
            temp = arr[i];
            cout << arr[i] << "\n";
            continue;
        }
        if(temp == arr[i]){
            continue;
        }
        cout << arr[i] << "\n";
        temp = arr[i];
    }
    
    return 0;
}
