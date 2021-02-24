#include <iostream>
#include <vector>
#define abs(x) (x>0? x : -x)

using namespace std;

void dp(vector<vector<int>> arr, vector<int> check, int sum, int now, int mnow, int nnow, int m, int &min){
    int stemp = sum;
    if(now >= check.size()){
        if(min < 0){
            min = sum;
        }
        else if(abs(sum) < min){
            min = abs(sum);
        }
        return;
    }
    if(nnow < m){
        check[now]=1;
        stemp = sum;
        for(int i=0;i<now;i++){
            if(check[i]==1){
                stemp += arr[now][i];
                stemp += arr[i][now];
            }
        }
        dp(arr, check, stemp, now+1, mnow, nnow+1, m, min);
    }
    
    if(mnow < m){
        check[now]=-1;
        stemp = sum;
        for(int i=0;i<now;i++){
            if(check[i]==-1){
                stemp -= arr[now][i];
                stemp -= arr[i][now];
            }
        }
        dp(arr, check, stemp, now+1, mnow+1, nnow, m, min);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    vector<int> check(n);
    
    for(int i=0;i<n;i++){
        vector<int> tmp(n);
        for(int j=0;j<n;j++){
            cin >> tmp[j];
        }
        arr.push_back(tmp);
    }
    
    int min=-1;
    int m = n/2;
    
    dp(arr, check, 0, 0, 0, 0, m, min);
    cout << min << "\n";
    return 0;
}
