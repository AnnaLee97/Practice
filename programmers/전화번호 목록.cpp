#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> m;
    bool answer = true;
    
    for(int i=0; i<phone_book.size();i++){
        m.insert({phone_book[i], true});
    }
    
    for(int i=0; i<phone_book.size();i++){
        if(answer){
            for(int j=1; j<phone_book[i].length(); j++){
                if(m.find(phone_book[i].substr(0,j))!=m.end()){
                    answer = false;
                    break;
                }
            }
        } else break;
    }
    
    return answer;
}
