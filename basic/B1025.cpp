//
// Created by Tom Guo on 24/12/2017.
// 注意：使用cin & cout会有一个节点超时
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct node {
    int address;
    int data;
    int next;
    node(int addr, int dat, int nex): address(addr), data(dat), next(nex) {}
};

vector<node> nodes; // nodes[i]表示id为i的节点
unordered_map<int, int> mp; // 通过节点地址查找节点id

// 获取地址为address的节点id
int id(int address) {
    if (mp.find(address) != mp.end())
        return mp.find(address)->second;
    return -1;
}

// 通过节点id获取下一个节点的id
int next(int id) {
    if (mp.find(nodes[id].next) != mp.end())
        return mp.find(nodes[id].next)->second;
    return -1;
}

// 判断节点是否有下一个节点
bool hasNext(int id) {
    return next(id) != -1;
}

// 判断从id节点开始，是否存在第k个节点
bool hasKthNode(int id, int k) {
    for (int i = 0; i < k - 1; ++i) {
        if (!hasNext(id))
            return false;
        id = next(id);
    }
    return true;
}

void solution() {

    int head, size, k;
    cin>>head>>size>>k;


    for (int i = 0; i < size; ++i) {

        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);

        mp[address] = i;
        nodes.push_back(node(address, data, next));

    }

    vector<node*> res;
    int p = id(head); // p为工作指针
    stack<node*> stk;
    while (p != -1) {
        stk.push(&nodes[p]);
        p = next(p);
        if (stk.size() == k) {
            while (!stk.empty()) {
                node* n = stk.top();
                res.push_back(n);
                stk.pop();
            }
        }
    }
    // 处理不需反转的部分
    stack<node*> sk;
    while (!stk.empty()) {
        node* n = stk.top();
        sk.push(n);
        stk.pop();
    }
    while (!sk.empty()) {
        node* n = sk.top();
        res.push_back(n);
        sk.pop();
    }

    // 输出部分
    printf("%.5d %d", res[0]->address, res[0]->data);
    for (int i = 1; i < res.size(); ++i)
        printf(" %.5d\n%.5d %d", res[i]->address, res[i]->address, res[i]->data);
    printf(" -1\n");

}

int main() {
    solution();
    return 0;
}