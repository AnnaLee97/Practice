#include <vector>


using namespace std;

int solution(int n) {
    int count = 0;
    vector<bool> temp(n+1, true);
    
    
    for(int i=2;i<=n;i++){
        for(int j=2;i*j<=n;j++){
            if(temp[i*j]) {
                temp[i*j] = false;
                count++;
            }
        }
    }
    
    return n-1-count;
}
