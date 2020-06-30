#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    while(n!=0){
        arr.push_back(n%10);
        n/=10;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
    cout<<"\n";
}
