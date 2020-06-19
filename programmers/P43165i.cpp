#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int value = 0;
    int flag=0;
    
    vector<int> stack;
    for(int i=0;i<numbers.size();){
        if(!flag){
            stack.push_back(0);
            value+=numbers.at(i);
        }
        else{
            stack.push_back(1);
            value-=numbers.at(i);
        }
        
        if(i==numbers.size()-1){
            if(value == target)
                answer++;
            while(stack.back()==1 && stack.size()!=0){
                value+=numbers.at(i);
                stack.pop_back();
                i--;
            }
            if(stack.size()==0)
                break;
            
            value-=numbers.at(i);
            stack.pop_back();
            flag=1;
            continue;
        }
        
        flag=0;
        i++;
    }
    return answer;
}
