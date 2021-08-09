#include <string>
#include <vector>
#include <utility>

using namespace std;

char score(int sc){
    char level='F';
    if(sc >= 90){
        level = 'A';
    } else if (sc >=80) {
        level = 'B';
    } else if (sc >= 70) {
        level = 'C';
    } else if( sc >= 50) {
        level = 'D';
    }
    
    return level;
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores[0].size();
    pair<int, int> max, min;
    int sc = 0;
    
    for(int i=0; i<n; i++){
        max = make_pair(0, scores[0][i]);
        min = make_pair(0, scores[0][i]);
        for(int j=1;j<n;j++){
            if(max.second < scores[j][i]){
                max = make_pair(j, scores[j][i]);
            } else if (max.second == scores[j][i] && max.first == i){
                max = make_pair(j, scores[j][i]);
            }
            
            if(min.second > scores[j][i]){
                min = make_pair(j, scores[j][i]);
            } else if (min.second == scores[j][i] && min.first == i){
                min = make_pair(j, scores[j][i]);
            }
        }
        
        if(max.first == i || min.first == i){
            scores[i][i] = 0;
        }
    }
    
    for(int i=0; i<scores[0].size(); i++){
        sc = 0;
        n = scores[0].size();
        for(int j=0; j<scores[0].size(); j++){
            if(scores[j][i]==0){
                n--; continue;
            }
            
            sc += scores[j][i];
        }
        
        if(n==0){
            answer += 'F'; continue;
        }

        answer += score((int)(sc/n));
    }
    
    return answer;
}
