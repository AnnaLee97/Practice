#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct node {
    int time;
    int ind;
    list<node>::iterator here;
    
    node(int t, int i){
        time = t;
        ind = i;
    }
};

bool compare(node a, node b){
    if(a.time == b.time) return a.ind < b.ind;
    else return a.time < b.time;
}

int solution(vector<int> food_times, long long k) {
    int now = -2;
    vector<node> arr;
    list<node> li;
    
    for(int i=0;i<food_times.size();i++){
        li.push_back(node(food_times[i], i));
        arr.push_back(node(food_times[i], i));
        auto it = li.end();
        arr[i].here = --it;
    }    
    
    sort(arr.begin(), arr.end(), compare);
    
    int size;
    int setloss = 0;
    int arrnow = 0;
    long long temp, n;
    
    while(k >= 0){
        size = li.size();
        if(size == 0) {
            break;
        }
        
        temp = (long long)(arr[arrnow].time - setloss)*size;
        
        if(k <= temp){
            if(k == temp && arr[arr.size()-1].time == arr[arrnow].time){
                break;
            }
            n = k % size;
            auto it = li.begin();
            for(long long i=0; i<n; i++){
                it++;
            }
            now = it->ind;
            break;
        }
        
        
        setloss = arr[arrnow].time;
        k -= temp;
        
        for(;arrnow<arr.size();arrnow++){
            auto it = arr[arrnow].here;
            it = li.erase(it);
            if(arrnow != arr.size()-1 && arr[arrnow+1].time != arr[arrnow].time){
                arrnow++;
                break;
            }
        }
        
        if(arrnow >= arr.size()) break;
        
    }
    
    
    return now+1;
}
