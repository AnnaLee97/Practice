#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = 0;
    int now = 0;
    string temp;
    
    while(count < k && now < number.size()){
        if(number.substr(now).length() <= k-count){
    		now = number.length(); break;
    	}
        temp = number.substr(now, k-count+1);
        auto it = max_element(temp.begin(), temp.end());
        answer += *it;
        count += it-temp.begin();
        now += it-temp.begin()+1;
    }
    
    answer += number.substr(now);
    
    return answer;
}
