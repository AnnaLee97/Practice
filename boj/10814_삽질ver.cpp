#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#include <utility> //pair가 이 안에 있음
#include <vector>

using namespace std;

class pairs {
    public: 
        int first;
        string second;
        int it;
        pairs(int j, string name, int i) {
            first = j;
            second = name;
            it = i;
        };
        pairs() {
            first = 0;
            second = "";
            it = 0;
        };

        pairs operator= (pairs& p) {
            first = p.first;
            second = p.second;
            it = p.it;
            return pairs(first, second, it);
        }
};

pairs make_pairs(int j, string name, int i) {
    pairs temp = pairs(j, name, i);
    return temp;
}

void swap(pairs &a, pairs &b) {
    pairs temp;

    temp = a;
    a = b;
    b = temp;
}

void insert(vector<pairs> &arr, pairs p, int i) {
    int j = i + 1;
    pairs temp;
    arr[j] = p;
    while (j != 0 && (arr[j / 2].first > arr[j].first || (arr[j/2].first == arr[j].first && arr[j/2].it > arr[j].it))) {
        temp = arr[j];
        arr[j] = arr[j / 2];
        arr[j / 2] = temp;
        j /= 2;
    }
}

void pop(vector<pairs>& arr, int num) {
    cout << arr[1].first << " " << arr[1].second << endl;
    int j = 1;
    int tmp;
    arr[1] = arr[num];
    arr.pop_back();
    num--;
    while (j < num) {
        if (2 * j >= num) break;
        if (2*j+1 >= num) {
            if (arr[2 * j].first < arr[j].first || (arr[2 * j].first == arr[j].first && arr[2 * j].it < arr[j].it)) {
                swap(arr[2 * j], arr[j]);
            }
            break;
        }
        tmp = (arr[2 * j].first < arr[2 * j + 1].first ? 2 * j : 2 * j + 1);
        if (arr[tmp].first < arr[j].first || (arr[tmp].first == arr[j].first && arr[tmp].it < arr[j].it)) {
            swap(arr[tmp], arr[j]);
            j = tmp;
            continue;
        }
        else {
            if (tmp == 2 * j) {
                if (arr[2 * j + 1].first < arr[j].first || (arr[2 * j+1].first == arr[j].first && arr[2 * j+1].it < arr[j].it)) {
                    swap(arr[2 * j + 1], arr[j]);
                    j = 2 * j + 1;
                }
                else break;
            }
            else {
                if (arr[2 * j].first < arr[j].first || (arr[2 * j].first == arr[j].first && arr[2 * j].it < arr[j].it)) {
                    swap(arr[2 * j], arr[j]);
                    j = 2 * j;
                }
                else break;
            }
        }
    }

}

int main() {
    int n;
    cin >> n;
    int j;
    string name;
    vector<pairs> arr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> j >> name;
        insert(arr, make_pairs(j, name, i), i);
    }

    for (int i = 0; i < n; i++) {
        pop(arr, n-i);
    }
    return 0;
}
