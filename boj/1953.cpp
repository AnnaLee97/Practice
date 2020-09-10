#include <cstdio>
#include <vector>
#include <stack>

#define conv(a) (a==0? 1:0)

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int temp;
    vector<vector<int>> v;
    for(int i=1;i<n;i++){
        vector<int> tmp(n+1,0);
        for(int j=0;j<n;j++){
            v.push_back(tmp);
        }
    }
    int t;
    for(int i=1;i<=n;i++){
        scanf("%d", &temp);
        for(int j=0;j<temp;j++){
            scanf("%d", &t);
            v[i][t]=1;
        }
    }
    stack<int> st;
    int now, i;
    vector<int> check(n+1,-1);
    check[1]=0; st.push(1);
    for(int j=1;j<=n;j++){
        if(check[j]==-1){
            st.push(j);
        }
        while(!st.empty()){
            now = st.top();
            st.pop();
            for(i=1;i<=n;i++){
                if(v[now][i] && check[i]==-1){
                    check[i] = conv(check[now]);
                    st.push(i);
                }
            }
        }
    }
    vector<int> a;
    vector<int> b;
    for(i=1;i<=n;i++){
        if(check[i]==0 || check[i]==-1){
            a.push_back(i);
        }
        else b.push_back(i);
    }
    printf("%d\n", a.size());
    for(int i=0;i<a.size();i++){
        printf("%d", a[i]);
        if(i!=a.size()-1){
            printf(" ");
        }
    }
    printf("\n%d\n", b.size());
    for(int i=0;i<b.size();i++){
        printf("%d", b[i]);
        if(i!=b.size()-1){
            printf(" ");
        }
        else printf("\n");
    }
}
