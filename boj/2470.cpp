#include <iostream>
#include <vector>
#include <algorithm>
#define abs(x) (x > 0 ? x : -x)

using namespace std;

class pa {
	public:
	    long long val;
	    int a, b;
	    
	    pa(long long v, int le, int ri){
	        val = v;
	        a = le;
	        b = ri;
	    }
};

bool compare(pa *a, pa *b){
    return a->val < b->val;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int start=0, end=arr.size()-1;
    long long temp;
    vector<pa *> cal;
    while(start != end){
        temp = arr[end]+arr[start];
        cal.push_back(new pa(abs(temp), arr[start], arr[end]));
        
        if(temp > 0){
            end--;
        } else if(temp < 0){
            start++;
        } else {
            cout << arr[start] << " " << arr[end] <<"\n";
            return 0;
        }
    }
    
    sort(cal.begin(), cal.end(), compare);
    
    cout << cal[0]->a << " " << cal[0]->b <<"\n";
    
    return 0;
}
