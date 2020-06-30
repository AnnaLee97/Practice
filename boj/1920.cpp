#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int n;
    int t;
    scanf("%d", &n);
    map<int, int> m;
    
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        m[temp] = 1;
    }
    cin >> t;
    for(int i=0;i<t;i++){
        scanf("%d", &temp);
        if(m[temp])
            printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}
