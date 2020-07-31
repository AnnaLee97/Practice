#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int k;
    scanf("%d\n", &k);
    stack<int> st;
    
    int temp;
    for(int i=0;i<k;i++){
        scanf("%d", &temp);
        if(temp) st.push(temp);
        else st.pop();
    }
    int sum=0;
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }
    
    printf("%d\n", sum);
    
    return 0;
}
