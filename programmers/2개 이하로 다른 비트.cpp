#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long find(long long num){
    long long ret = num;
    string s = "";
    
    while(num%2 != 0){
        s = (char)(num%2 + '0') + s;
        num /= 2;
    }
    
    if(s.length() > 0){
        ret += pow(2, s.length()-1);
    } else {
        ret += 1;
    }
    
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();i++){
        answer.push_back(find(numbers[i]));
    }
    
    return answer;
}
