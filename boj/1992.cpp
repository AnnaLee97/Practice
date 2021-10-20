#include <iostream>
#include <vector>
#include <string>

using namespace std;

string zip(vector<string> arr, int srow, int erow, int scol, int ecol){
    string ret= "";
    string temp;
    int halfr = (srow + erow)/2;
    int halfc = (scol + ecol)/2;
    
    if(erow == srow){
        ret += arr[srow][scol];
        return ret;
    }
    
    temp = zip(arr, srow, halfr, scol, halfc);
    ret += temp;
    
    temp = zip(arr, srow, halfr, halfc+1, ecol);
    ret += temp;
    
    temp = zip(arr, halfr+1, erow, scol, halfc);
    ret += temp;
    
    temp = zip(arr, halfr+1, erow, halfc+1, ecol);
    ret += temp;
    
    
    if(ret == "0000") ret = "0";
    else if(ret == "1111") ret = "1";
    else {
        ret = "(" + ret + ")";
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    string ret = zip(arr, 0, n-1, 0, n-1);
    
    cout << ret;
    
    return 0;
}
