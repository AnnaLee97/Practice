#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string temp;
    int max, min, t;
    ss >> temp;
    max = stoi(temp); min = max;
    
    while(ss >> temp){
        t = stoi(temp);
        if(min > t) min = t;
        if(max < t) max = t;
    }
    answer += to_string(min) +' '+to_string(max);
    
    return answer;
}
