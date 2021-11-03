#include <string>
#include <vector>

using namespace std;

void dfs(int &ans, vector<int> arr, int now, int n, int col){
    arr[col] = now++;
    
    if(now == n){
        ans++;
        return;
    }
    
    vector<bool> check(n, true);
    
    for(int i=0;i<n;i++){
        if(arr[i] != -1){
            check[i] = false;
            
            if(i-(now-arr[i]) >= 0){ //대각선 위
                check[i-(now-arr[i])] = false;
            }
            if(i+(now-arr[i]) < n) { //대각선 아래
                check[i+(now-arr[i])] = false;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(check[i]){
            dfs(ans, arr, now, n, i);
        }
    }
    
    return;
}

int solution(int n) {
    int answer = 0;
    vector<int> arr(n, -1);
    
    for(int i=0;i<n;i++){
        dfs(answer, arr, 0, n, i);
    }
    
    
    return answer;
}
