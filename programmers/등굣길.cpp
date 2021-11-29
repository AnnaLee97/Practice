#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> check(m+1, vector<long long>(n+1, 0));
    
    for(int i=0;i<puddles.size();i++){
        check[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    check[1][1] = 1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(check[i][j] == -1) check[i][j] = 0;
            else {
                check[i][j] += (check[i-1][j] + check[i][j-1]) % 1000000007;
            }
        }
    }
    return check[m][n];
}
