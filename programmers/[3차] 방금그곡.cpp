#include <string>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

int length(string str);

string substr(string str, int pos, int len){
    string ret = "";
    int slen = length(str);
    int start=0, end = 0;
    int temp=-1;
    
    if(len == 0) return "";
    
    if(slen <= len){
        end = str.length()-1;
    }
    
    for(int i=0;i<str.length();i++){
        temp++;
        if(temp == pos){
            start = i;
        }
        if(i+1 < str.length() && str[i+1] =='#'){
            i++;
        }
        if(temp == pos+len-1){
            end = i;
            break;
        }
    }
    return str.substr(start, end-start+1);
}

int length(string str){
    int len = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] != '#'){
            len++;
        }
    }
    return len;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> temp(4);
    int time, len, ind;
    string s;
    
    pair<int, string> music = make_pair(-1, "");
    
    for(int i=0;i<musicinfos.size();i++){
        stringstream ss(musicinfos[i]);
        
        for(int j=0;j<4;j++){
            getline(ss, temp[j], ',');
        }
        
        //재생시간
        time = stoi(temp[1].substr(0,2))*60;
        time += stoi(temp[1].substr(3));
        time -= stoi(temp[0].substr(0,2))*60;
        time -= stoi(temp[0].substr(3));
        
        len = length(temp[3]);
        s = "";
        
        if(len >= time){
            s = substr(temp[3], 0, time);
        } else {
            for(int k=0; k< time/len ; k++){
                s += temp[3];
            }
            s += substr(temp[3], 0, time%len);
        }
        
        while(true){
            if(s.find(m) != string::npos){
                ind = s.find(m);

                if(ind+m.length() >= s.length()){
                    if(music.first < time){
                        music.first = time;
                        music.second = temp[2];
                    }
                    break;
                } else {
                    if(s[ind+m.length()] != '#'){
                        if(music.first < time){
                            music.first = time;
                            music.second = temp[2];
                        }
                        break;
                    } else {
                        s = s.substr(ind+m.length()+1);
                    }
                }
            } else {
                break;
            }
        }
        
       
    }
    
    if(music.first == -1){
        answer = "(None)";
    } else {
        answer = music.second;
    }
    
    return answer;
}
