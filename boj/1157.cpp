#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using std::transform;

bool compare(vector<int> le, vector<int> ri){
    return le[1] > ri[1];
}


int main(){
    string str;
    char tmp[1000002];
    scanf("%s", tmp);
    str = (string)tmp;

    vector<vector<int>> arr(26);
    for(int i=0;i<26;i++){
        arr[i].push_back(i);
        arr[i].push_back(0);
    }
    int temp;
    for(int i=0;i<str.length();i++){
        if(str[i] < 'a')
            temp = str[i]-'A';
        else temp = str[i]-'a';
        arr[temp][1]++;
    }
    sort(arr.begin(), arr.end(), compare);
    if(arr[0][1]==arr[1][1])
        printf("?\n");
    else printf("%c\n", 'A'+arr[0][0]);
    return 0;
}
