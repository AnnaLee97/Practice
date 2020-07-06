#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string st;
    cin >> st;
    sort(st.begin(), st.end(), greater<char>());
    cout << st <<"\n";
    return 0;
}
