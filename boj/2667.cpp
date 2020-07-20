#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void trav(vector<vector<int>>& check, vector<vector<int>> arr, int i, int j, int count, vector<int>& num) {
    check[i][j] = 1;
    num[count - 1]++;

    if (i != check[i].size() - 1 && arr[i + 1][j] && !check[i+1][j]) {
        trav(check, arr, i + 1, j, count, num);
    }

    if (j != 0 && arr[i][j - 1] && !check[i][j-1]) {
        trav(check, arr, i, j - 1, count, num);
    }

    if (j != check[i].size() - 1 && arr[i][j + 1] && !check[i][j+1]) {
        trav(check, arr, i, j + 1, count, num);
    }

    if (i != 0 && arr[i - 1][j] && !check[i-1][j]) {
        trav(check, arr, i - 1, j, count, num);
    }

    return;
}

int main() {
    int n;
    int count = 0;
    vector<int> num;
    scanf("%d\n", &n);
    vector<vector<int>> arr(n);
    vector<vector<int>> check;
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &tmp);
            arr[i].push_back(tmp - '0');
        }
        if (i != n - 1)
            scanf("%c", &tmp);
        vector<int> temp(n,0);
        check.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] && !check[i][j]) {
                count++;
                num.push_back(0);
                trav(check, arr, i, j, count, num);
            }
        }
    }

    sort(num.begin(), num.end());
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d\n", num[i]);
    }

    return 0;
}
