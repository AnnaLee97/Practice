#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class file {
    public:
        int ind;
        string head;
        int number;
    
    file(int index, string str){
        ind = index;
        
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        int i, start=-1, end = str.length();
        string temp="";
        for(i=0;i<str.length();i++){
            if(str[i] >= '0' && str[i]<='9'){
                temp += str[i];
                if(start == -1) start = i;
            } else if(start != -1){
                end = i;
                break;
            }
        }
        head = str.substr(0, start);
        number = stoi(temp);
    }
    
};

bool compare(file *a, file *b){
    if(a->head == b->head){
        if(a->number == b->number){
            return a->ind <= b->ind;
        } else return a->number < b->number;
    } else return a->head < b->head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file *> temp;
    
    for(int i=0;i<files.size();i++){
        temp.push_back(new file(i, files[i]));
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    for(int i=0;i<temp.size();i++){
        answer.push_back(files[temp[i]->ind]);
    }
    
    return answer;
}
