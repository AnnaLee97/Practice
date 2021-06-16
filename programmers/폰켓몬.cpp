#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size()/2;
    
    set<int> s(nums.begin(), nums.end());
    
    if(s.size() > n) answer = n;
    else answer = s.size();
    
    return answer;
}
