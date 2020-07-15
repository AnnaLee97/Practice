#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;



int main(){
    int n;
    scanf("%d", &n);
    stack<int> st;
    vector<char> result;
    
    int now;
    int j=1;
    int flag = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &now);
        if(st.empty()){
            for(j;j<=now;j++){
                st.push(j);
                result.push_back('+');
            }
            result.push_back('-');
            st.pop();
        }
        else{
            if(st.top() == now){
                result.push_back('-');
                st.pop();
            }
            else{
                if(now < st.top()){
                    printf("NO\n");
                    flag = 1;
                    return 0;
                }
                for(j;j<=now;j++){
                    st.push(j);
                    result.push_back('+');
                }
                result.push_back('-');
                st.pop();
                }
        }
    }
    if(flag==0){
        for(int i=0;i<result.size();i++){
            printf("%c\n", result[i]);
        }
    }
    
    return 0;
}
