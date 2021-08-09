#include <string>
#include <vector>
#include <utility>
#include <cstdlib>


using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int row, col;
    int l,r;
    pair<int, int> left=make_pair(3,0), right=make_pair(3,2);
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]==0){
            row = 3; col = 1;
        }else {
            row = (numbers[i]-1)/3;
            col = (numbers[i]-1)%3;
        }
        
        
        if(col == 0){
            answer += 'L';
            left = make_pair(row,col);
        } else if(col == 2){
            answer += 'R';
            right = make_pair(row,col);
        } else {
            l = abs(row-(left.first))+abs(col-(left.second));
            r = abs(row-(right.first))+abs(col-(right.second));
          
            if( l < r ){
                answer += 'L';
                left = make_pair(row,col);
            }else if(l > r){
                answer += 'R';
                right = make_pair(row,col);
            } else {
                if(hand == "left"){
                    answer += 'L';
                    left = make_pair(row,col);
                }else {
                    answer += 'R';
                    right = make_pair(row,col);
                }
            }
        }
    }

    return answer;
}
