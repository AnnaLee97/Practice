#include <iostream>
#include <vector>

using namespace std;

void find(int n, int s, int ind, int val, int& count, vector<int> arr);

int main() {
    int n, s;
    vector<int> arr;
    int temp;
    cin >> n >> s;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < arr.size(); i++) {
        find(n, s, i, 0, count, arr);
    }

    cout << count << endl;

    return 0;
}

void find(int n, int s, int ind, int val, int& count, vector<int> arr) {
    int i;
    val += arr[ind];
    if (val == s) {
        count++;
    }

    for (i = ind + 1; i < n; i++) {
        find(n, s, i, val, count, arr);
    }
}
