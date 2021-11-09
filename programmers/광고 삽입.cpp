#include <string>
#include <vector>
#include <sstream>

using namespace std;

long long caltime(string time){
    long long ret = 0;
    stringstream ss(time);
    string s;
    
    while(getline(ss, s, ':')){
        ret = 60*ret + stoi(s);
    }
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    if(play_time == adv_time) return "00:00:00";
    
    string answer = "";   
    long long playtime = caltime(play_time);
    long long advtime = caltime(adv_time);
    
    vector<long long> check(playtime+1, 0);
    long long start, end;
    for(int i=0;i<logs.size();i++){
        start = caltime(logs[i].substr(0, 8));
        end = caltime(logs[i].substr(9));
        
        check[start]++;
        check[end]--;
    }
    //시간별 시청자수 계산
    for(int i=1;i<check.size();i++){
        check[i] += check[i-1];
    }
    
    //sum
    long long max = 0;
    for(int i=0;i<advtime;i++){
           max += check[i];
    }
    
    long long temp = max;
    start = 0;
    end = playtime - advtime;
    
    for(int i=1;i<=end;i++){
        temp  = temp - check[i-1] + check[i+advtime-1];
        
        if(temp > max){
            max = temp;
            start = i;
        }
    }
    
    string s = to_string(start / 3600);
    if(s.length() == 1) s = "0" + s;
    answer += s;
    start %= 3600;
    s = to_string(start / 60);
    if(s.length() == 1) s = "0" + s;
    answer += ":" + s;
    start %= 60;
    s = to_string(start);
    if(s.length() == 1) s = "0" + s;
    answer += ":" + s;

    
    return answer;
}
