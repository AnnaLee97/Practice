#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr.begin(), arr.end());
    
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]>=x){
                if(arr[i]+arr[j]==x)
                    count++;
                break;
            } 
        }
    }
    cout << count;
    return 0;
}
