#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    vector<pair<int, int>> ppl;
    int n;
    
    cin >> n;
    vector<int> res(n,1);
    int w, h;
    for(int i=0;i<n;i++){
        cin >> w >> h;
        ppl.push_back(make_pair(w,h));
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ppl[i].first > ppl[j].first && ppl[i].second > ppl[j].second)
                res[j]++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout << res[i]<<endl;
    }

    return 0;
}
