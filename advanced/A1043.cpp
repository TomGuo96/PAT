//
// Created by Tom Guo on 23/10/2017.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node* &root, int data){
    if(root == NULL){
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// vi存储前序遍历结果
void preOrder(node* root, vector<int>& vi){
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

// vi存储前序遍历结果
void preOrderMirror(node* root, vector<int>& vi){
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int>& vi){
    if(root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>& vi){
    if(root == NULL)
        return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

void solution(){

    int size, data;
    vector<int> origin, pre, preM, post, postM;
    node* root = NULL;
    cin>>size;
    for(int i = 0; i < size; i++){
        cin>>data;
        origin.push_back(data);
        insert(root, data);
    }

    // 求出几个遍历序列
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);

    if (origin == pre){
        cout<<"YES\n";
        for(int i = 0; i < (int)post.size(); i++){
            cout<<post[i];
            if(i < (int)post.size() - 1)
                cout<<" ";
        }
        cout<<endl;
    } else if(origin == preM){
        cout<<"YES\n";
        for(int i = 0; i < (int)postM.size(); i++){
            cout<<postM[i];
            if(i < (int)postM.size() - 1)
                cout<<" ";
        }
        cout<<endl;
    } else
        cout<<"NO\n";

}


int main() {
    /**
     * 测试用例：
     * 7 8 6 5 7 10 8 11
     * 期待输出：
     * YES
     * 5 7 6 8 11 10 8
     *
     * 测试用例：
     * 7 8 10 11 8 6 7 5
     * 期待输出：
     * YES
     * 11 8 10 7 5 6 8
     */
    solution();
    return 0;
}
