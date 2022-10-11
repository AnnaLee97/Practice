#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main() {
    int n, k, temp;
    int count = 0;
    
    cin >> n >> k;
    
    list<pair<bool, int>> li;
    list<pair<bool, int>> q;
    for (int i=0;i<2*n;i++) {
        cin >> temp;
        if (i < n) {
            li.push_back(make_pair(false, temp));
        } else {
            q.push_front(make_pair(false, temp));
        }
    }
    
    int step = 1;
    while (count < k) {        
        // 1.
        li.push_front(q.front());
        q.push_back(li.back());
        li.pop_back();
        q.pop_front();
        li.back().first = false;        
        
        // 2.
        if (count < k) {
            for (auto it = li.rbegin(); it != li.rend(); it++) {
                if (it == li.rbegin()) continue;
                auto tempit = prev(it, 1);
                if (it->first && !(tempit->first) && (tempit->second) > 0) {
                    it->first = false;
                    if (tempit != li.rbegin()) {
                        tempit->first = true;
                    }
                    tempit->second--;
                    if (tempit->second == 0) {
                        count++;
                    }
                }
                if (count >= k) break;
            }
        }
        
        // 3.
        if (count < k && !li.front().first && li.front().second > 0) {
            li.front().first = true;
            li.front().second--;
            if (li.front().second == 0) {
                count++;
            }
        }
        
        // 4.
        if (count < k) {
            step++;
        }
    }
    
    cout << step << "\n";
    
    return 0;
}
