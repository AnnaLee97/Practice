#include <string>
#include <vector>
#define max(a, b) (a > b ? a : b)

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<vector<int>> check(money.size(), vector<int>(4, 0));

    check[0][1] = -1;
    check[0][2] = -1;
    check[0][3] = money[0];
    
    for(int i=1;i<money.size();i++){
        //select now
        for(int j=0;j<=1;j++){
            if(check[i-1][j] == -1){
                check[i][j+2] = -1;
            }
            else {
                check[i][j+2] = check[i-1][j] + money[i];
            }
        }
        
        //not select
        for(int j=0;j<=1;j++){
            check[i][j] = max(check[i-1][0+j], check[i-1][2+j]);
        }
    }
    
    int last = (int)money.size()-1;
    answer = max(check[last][0], check[last][1]);
    answer = max(answer, check[last][2]);
    
    return answer;
}
