#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> arr;
    map<string, string> dic;
    
    string a,b,c;
    
    for(int i=0;i<record.size();i++){
        istringstream ss(record[i]);
        ss >> a >> b;
        if(a[0] != 'L'){
            ss >> c;
            dic[b]=c;
        }
        
        if(a[0] != 'C'){
            arr.push_back({a,b});
        }
    }
    string temp;
    for(int i=0; i<arr.size();i++){
        temp=dic[arr[i][1]];
        if(arr[i][0][0]=='E'){
            temp += "님이 들어왔습니다.";
        }else{
            temp += "님이 나갔습니다.";
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}
