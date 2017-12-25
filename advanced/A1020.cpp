#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 50;

int pre[maxn], in[maxn], post[maxn];
int number;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* create(int postL, int postR, int inL, int inR){
    if(postL > postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR])
            break;
    }
    // 左子树节点个数
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

// 已经输出的节点的个数
int num = 0;
void leverOrder(node* root){

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        cout<<now->data;
        num++;
        if(num < number)
            cout<<" ";
        if(now->lchild != NULL)
            q.push(now->lchild);
        if(now->rchild != NULL)
            q.push(now->rchild);
    }

}

void solution(){

    cin>>number;
    for(int i = 0; i < number; i++)
        cin>>post[i];
    for(int i = 0; i < number; i++)
        cin>>in[i];

    node* root = create(0, number - 1, 0, number - 1);
    leverOrder(root);

    return;

}

int main() {
    /**
     * case: 7 2 3 1 5 7 6 4 1 2 3 4 5 6 7
     * result: 4 1 6 3 5 7 2
     */
    solution();
    return 0;
}