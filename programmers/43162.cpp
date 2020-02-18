#include <string>
#include <vector>

using namespace std;
int check(vector<vector <int>> computers, vector<int> &temp, int d);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        if(!temp[i])
            answer += check(computers, temp, i);
    }
    return answer;
}

int check(vector<vector <int>> computers, vector<int> &temp, int d){
    temp[d] = 1;
    for(int i=0;i<temp.size();i++){
        if(computers[d][i] && !temp[i]){
            check(computers, temp, i);
        }
    }
    return 1;
}
