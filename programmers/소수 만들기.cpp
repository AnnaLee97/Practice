#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void makeprime(vector<int> &arr, map<int,int> &m, int num, int &lastcheck){
    bool flag;
    for(int j=lastcheck+1; j<=num;j++){
        flag = true;
        for(int i=0; i<arr.size();i++){
            if(j%arr[i]==0){
                flag = false;
                break;
            }
        }
        if(flag){
            m[j] = 1;
            arr.push_back(j);
        }
    }
    lastcheck = num;
    return;
}

int go(vector<int> nums, vector<int> &arr, map<int,int> &m, int sum, int &count, int dep, int now, int &lastcheck){    
    if(dep == 3){
        if(lastcheck < sum){
            makeprime(arr, m, sum, lastcheck);
        }        
        if(m.find(sum) != m.end()){
            count++;
        }

        return count;
    }
    
    for(int j=now; j<nums.size();j++){
        count = go(nums, arr, m, sum+nums[j], count, dep+1, j+1, lastcheck);
    }
    return count;
}

int solution(vector<int> nums) {
    vector<int> arr(1,2);
    map<int, int> m;
    m[2]=0;
    int count = 0;
    int lastcheck = 2;

    sort(nums.begin(), nums.end());
    count = go(nums, arr, m, 0, count, 0, 0, lastcheck);

    return count;
}
