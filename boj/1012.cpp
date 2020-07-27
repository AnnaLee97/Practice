#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

void trav(vector<vector<int>> arr, vector<vector<int>> &check, int i, int j){
    check[i][j]++;
    stack<vector<int>> st;
    
    if(i!=0 && arr[i-1][j] && !check[i-1][j]){
        trav(arr, check, i-1, j);
    }
    if(i!=arr.size()-1 &&  arr[i+1][j] && !check[i+1][j]){
        trav(arr, check, i+1, j);
    }
    if(j!=0 &&  arr[i][j-1] && !check[i][j-1]){
        trav(arr, check, i, j-1);
    }
    if(j!=arr[0].size()-1 &&  arr[i][j+1] && !check[i][j+1]){
        trav(arr,check,i,j+1);
    }
    return;
}

int main(){
    int T;
    int m,n,k;
    int res;
    vector<vector<int>> arr;
    vector<vector<int>> check;
    scanf("%d\n", &T);
    for(int t=0;t<T;t++){
        res = 0;
        scanf("%d %d %d\n", &m, &n, &k);

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            arr.push_back(temp);
            check.push_back(temp);
        }
        int le, ri;
        for(int i=0;i<k;i++){
            scanf("%d %d", &le, &ri);
            arr[le][ri]++;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] && !check[i][j]){
                    res++;
                    trav(arr, check, i, j);
                }
            }
        }
        
        printf("%d\n", res);
       
        arr.clear();
        check.clear();
    }
    
    return 0;
}
