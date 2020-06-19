#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i;
    map<string,int> cdic;
    
    for(i=0;i<completion.size();i++){
        cdic[completion.at(i)]++;
    }
    for(i=0;i<participant.size();i++){
        if(cdic[participant.at(i)]==0){
            answer = participant.at(i);
            break;
        }
        cdic[participant.at(i)]--;
    }
    return answer;
}
