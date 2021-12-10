#include <string>
#include <vector>
#define max(a, b) (a > b ? a : b)

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int count;
    
    for(int i=0;i<places.size();i++){
        bool flag = false;
        
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k] != 'X'){
                    count = 0;
                    if(j!=0 && places[i][j-1][k] == 'P') count++;
                    if(k!=0 && places[i][j][k-1] == 'P') count++;
                    if(k!=4 && places[i][j][k+1] == 'P') count++;
                    if(j!=4 && places[i][j+1][k] == 'P') count++;
                    
                    if(count > 1 || (places[i][j][k] == 'P' && count == 1)){
                        flag = true;
                        answer.push_back(0);
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(!flag) answer.push_back(1);
    }
    
    
    return answer;
}
