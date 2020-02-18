#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int i=0, j=0, k=0;
    
    for(int ind = 0; ind < answers.size(); ind++){
        if(ind%5 +1 == answers[ind]) i++;
        if(ind %2 == 0 && answers[ind] == 2) j++;
        else if(ind%2 == 1){
            if(((ind)/2)%4 == 0 && answers[ind] == 1) j++;
            else if(((ind)/2)%4 != 0 && answers[ind] == ((ind)/2)%4+2) j++;
        }
        switch((ind/2)%5){
            case 0: if(answers[ind]==3) k++;
                break;
            case 1: if (answers[ind]==1) k++;
                break;
            case 2: if(answers[ind]==2) k++;
                break;
            case 3: if(answers[ind]==4) k++;
                break;
            case 4: if(answers[ind]==5) k++;
                break;
        }
    }

    
    if(i>j){
        if(i>=k){
            answer.push_back(1);
            if(i==k)
                answer.push_back(3);
        }
        else{
            answer.push_back(3);
        }
    }
    else if(i==j){
        if(i>=k){
            answer.push_back(1);
            answer.push_back(2);
            if(i==k)
                answer.push_back(3);
        }
        else
            answer.push_back(3);
    }
    else if(i < j){
        if(j>= k){
            answer.push_back(2);
            if(j==k)
                answer.push_back(3);
        }
        else
            answer.push_back(3);
    }
    
    return answer;
}
