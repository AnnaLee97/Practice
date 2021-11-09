#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int x, y;
    node *left, *right;
    
    node(int x, int y){
        this->x = x;
        this->y = y;
        left = NULL;
        right = NULL;
    }
    
    void insert(node *n){
        node *temp = this;
        while(1){
            if(temp->x > n->x){
                if(temp->left == NULL){
                    temp -> left = n;
                    break;
                } else {
                    temp = (temp->left);
                }
            } else {
                if(temp->right == NULL){
                    temp -> right = n;
                    break;
                } else {
                    temp = (temp->right);
                }
            }
        }
        return;
    }
};

bool compare(vector<int> a, vector<int> b){
    if(a[1] == b[1]) return a[0] < b[0];
    else return a[1] > b[1];
}

void preorder(vector<vector<int>> &answer, node *now, map<int, int> dic){
    answer[0].push_back(dic[now->x]);
    
    if(now->left != NULL)
        preorder(answer, now->left, dic);
    if(now->right != NULL)
        preorder(answer, now->right, dic);
    return;
}

void postorder(vector<vector<int>> &answer, node *now, map<int, int> dic){
    if(now->left != NULL)
        postorder(answer, now->left, dic);
    if(now->right != NULL)
        postorder(answer, now->right, dic);
    
    answer[1].push_back(dic[now->x]);
    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    node *top = NULL;
    map<int, int> numbering;
    
    for(int i=0;i<nodeinfo.size();i++){
        numbering[nodeinfo[i][0]] = i+1;
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    
    node *temp;
    for(int i=0;i<nodeinfo.size();i++){
        temp = new node(nodeinfo[i][0], nodeinfo[i][1]);
        
        if(top == NULL){
            top = temp;
        }
        else {
            top->insert(temp);
        }        
    }
    
    preorder(answer, top, numbering);
    postorder(answer, top, numbering);
    
    return answer;
}
