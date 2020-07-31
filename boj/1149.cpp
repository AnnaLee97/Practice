#include <iostream>
#include <cstdio>
#include <vector>
#define min(a, b) (a<b ? a : b)

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    vector<vector<int>> color(3);
    //red, green, blue
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &temp);
            color[j].push_back(temp);
        }
    }

    vector<vector<int>> check;
    vector<int> t(n);
    check.push_back(t);
    check.push_back(t);
    check.push_back(t);
    check[0][0] = color[0][0];
    check[1][0] = color[1][0];
    check[2][0] = color[2][0];
    for(int i=1;i<n;i++){
        check[0][i] = min(check[1][i-1], check[2][i-1]) + color[0][i];
        check[1][i] = min(check[0][i-1], check[2][i-1]) + color[1][i];
        check[2][i] = min(check[0][i-1], check[1][i-1]) + color[2][i];
    }
    
    int tmp = min(check[0][n-1], check[1][n-1]);
    tmp = min(tmp, check[2][n-1]);
    printf("%d\n", tmp);
    
    return 0;
}
