#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int min = -1;
    int t = 0, tt = 0;
    vector<vector<bool>> arr;

    char temp;
    scanf("%c", &temp);
    for (int i = 0; i < m; i++) {
        vector<bool> tmp;
        for (int j = 0; j < n; j++) {
            scanf("%c", &temp);
            if (temp == 'W') {
                tmp.push_back(true);
            }
            else tmp.push_back(false);
        }
        if(i!=m-1)
            scanf("%c", &temp);
        arr.push_back(tmp);
    }
    bool now, now2;
    int ttt;
    for (int i = 0; i < m - 7; i++) {
        for (int j = 0; j < n - 7; j++) {
            now = true;
            now2 = false;
            t = tt = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if (arr[k][l] != now) {
                        t++;
                    }
                    if (arr[k][l] != now2) {
                        tt++;
                    }
                    if (l!=j+7) {
                        now = !now;
                        now2 = !now2;
                    }
                }
            }
            if (min == -1) {
                min = (t < tt ? t : tt);
            }
            else {
                ttt = (t < tt ? t : tt);
                min = (min < ttt ? min : ttt);
            }
        }
    }

    printf("%d\n", min);

    return 0;
}
