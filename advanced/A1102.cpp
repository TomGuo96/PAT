//
// Created by Tom Guo on 11/12/2017.
//

#include <iostream>
#include <queue>

using namespace std;

// 反转后二叉树的层序遍历
void levelOrder(int tree[][2], int root, int count) {

    queue<int> que;
    que.push(root);
    int cnt = 0; // 已经输出节点个数
    while (!que.empty()) {

        int x = que.front();
        if (cnt < count - 1)
            cout << x << " ";
        else
            cout << x << endl;
        cnt++;
        que.pop();

        if (tree[x][1] != -1)
            que.push(tree[x][1]);
        if (tree[x][0] != -1)
            que.push(tree[x][0]);

    }

}

// 反转后二叉树的中序遍历
void inOrder(int tree[][2], int root, int count, int &cnt) {

    if (tree[root][1] != -1)
        inOrder(tree, tree[root][1], count, cnt);
    if (cnt < count - 1)
        cout << root << " ";
    else
        cout << root << endl;
    cnt++;
    if (tree[root][0] != -1)
        inOrder(tree, tree[root][0], count, cnt);

}

void solution() {

    int count;
    cin >> count;

    int tree[count][2]; // tree[x][0] tree[x][1]表示第x号节点的左右孩子
    int isRoot[count]; // 标记节点是否为根结点
    fill(isRoot, isRoot + count, 0);

    char child;
    for (int i = 0; i < count; i++) {

        cin >> child;
        isRoot[child - '0'] = 1;
        if (child == '-')
            tree[i][0] = -1;
        else
            tree[i][0] = child - '0';

        cin >> child;
        isRoot[child - '0'] = 1;
        if (child == '-')
            tree[i][1] = -1;
        else
            tree[i][1] = child - '0';

    }

    // 找到根结点root
    int root = -1;
    for (int i = 0; i < count; i++) {
        if (isRoot[i] == 0) {
            root = i;
            break;
        }
    }

    levelOrder(tree, root, count);
    int cnt = 0;
    inOrder(tree, root, count, cnt);

}

int main() {
    solution();
    return 0;
}