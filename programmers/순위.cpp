#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> check(n+1, vector<bool>(n+1, false));
    
    for(int i=0;i<results.size();i++){
        check[results[i][0]][results[i][1]] = true;
    }

    for(int now=1;now<=n;now++){
        for(int i=1;i<=n;i++){
            if(i == now) continue;
            for(int j=1;j<=n;j++){
                if(i==j || j == now) continue;
                
                if(check[i][now] && check[now][j])
                    check[i][j] = true;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(check[i][j] || check[j][i]) count++;
        }
        if(count == n-1) answer++;
    }
    
    
    return answer;
}
