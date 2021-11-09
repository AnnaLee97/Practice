#include <vector>

using namespace std;

void dfs(int m, int n, vector<vector<int>> picture,  vector<vector<int>> &check, int row, int col, int num, int &count){
    check[row][col] = num;
    count++;
    
    for(int i=-1;i<=1;i+=2){
        if(row+i >= 0 && row+i < m && check[row+i][col] == -1 && picture[row][col] == picture[row+i][col]){
            dfs(m, n, picture, check, row+i, col, num, count);
        }
    }
    for(int i=-1;i<=1;i+=2){
        if(col+i >= 0 && col+i < n && check[row][col+i] == -1 && picture[row][col] == picture[row][col+i]){
            dfs(m, n, picture, check, row, col+i, num, count);
        }
    }
    
    return;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int count;
    vector<vector<int>> check(m, vector<int>(n, -1));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j] != 0 && check[i][j] == -1){
                count = 0;
                dfs(m, n, picture, check, i, j, ++number_of_area, count);
                if(max_size_of_one_area < count) max_size_of_one_area = count;
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
