#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

typedef struct node *nodepointer;
typedef struct node{
    nodepointer left;
    nodepointer right;
    int flag;
    char me;
    
    node(char &c){
        this->me = c;
        this->left = NULL;
        this->right = NULL;
        this->flag = 0;
    }
};

stack<nodepointer> st;

void pre(){
    nodepointer top;
    
    while(!st.empty()){
        top = st.top();

        if(top->flag == 0){
            printf("%c", top->me);
            top->flag = 1;
            if(top->left != NULL)
                st.push(top->left);
        }
        else if(top->flag==1){
            top->flag = 2;
            if(top->right != NULL)
                st.push(top->right);
            else st.pop();
        }
        else st.pop();
    }
}

void in(){
    nodepointer top;
    
    while(!st.empty()){
        top = st.top();

        if(top->flag == 0){
            top->flag = 1;
            if(top->left != NULL)
                st.push(top->left);
        }
        else if(top->flag==1){
            printf("%c", top->me);
            top->flag = 2;
            if(top->right != NULL)
                st.push(top->right);
            else {
                st.pop();
            }
        }
        else st.pop();
    }
}

void post(){
    nodepointer top;
    
    while(!st.empty()){
        top = st.top();

        if(top->flag == 0){
            top->flag = 1;
            if(top->left != NULL)
                st.push(top->left);
        }
        else if(top->flag==1){
            top->flag = 2;
            if(top->right != NULL)
                st.push(top->right);
            else {
                printf("%c", top->me);
                st.pop();
            }
        }
        else {
            printf("%c", top->me);
            st.pop();
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<nodepointer> arr(n);
    char temp, le, ri;
    char tmp;
    for(int i=0;i<n;i++){
        tmp = 'A'+i;
        arr[i] =  new node(tmp);
    }
    for(int i=0;i<n;i++){
        scanf("\n%c %c %c", &temp, &le, &ri);
        if(le == '.' && ri=='.') continue;
        else{
            if(le != '.')
                arr[temp-'A']->left = arr[le-'A'];
            if(ri != '.')
                arr[temp-'A']->right = arr[ri-'A'];
        }
    }
    
    st.push(arr[0]);
    pre();
    printf("\n");
    for(int i=0;i<n;i++){
        arr[i]->flag = 0;
    }
    st.push(arr[0]);
    in();
    printf("\n");
    for(int i=0;i<n;i++){
        arr[i]->flag = 0;
    }
    st.push(arr[0]);
    post();
    printf("\n");
    
    return 0;
}
