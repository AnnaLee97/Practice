#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(pair<int, string> t, pair<int, string> tt) {
    return t.first < tt.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        
    }

    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}
