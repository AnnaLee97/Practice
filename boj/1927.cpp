#include <cstdio>
#include <queue>
#include <vector>


using namespace std;

int main(){
    int n, x;
    scanf("%d\n", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        if(x){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
    
    return 0;
}
