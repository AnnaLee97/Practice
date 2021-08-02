#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    char c=words[0][words[0].length()-1];
    map<string, int> m;
    
    m[words[0]] = 1; 
    for(int i=1;i<words.size();i++){
        if(words[i][0] != c || m.find(words[i]) != m.end()){
            answer[0] = i%n + 1;
            answer[1] = i/n + 1;
            break;
        }
        m[words[i]]=1;
        c=words[i][words[i].length()-1];
    }


    return answer;
}
