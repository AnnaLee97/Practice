#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int temp=0;
    for(int i=0;i<n;i++){
        temp += arr[i]*(n-i);
    }
    cout << temp << "\n";
    
    return 0;
}
