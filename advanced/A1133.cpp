//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct node {
    int address, data, next;
    bool valid;

    node() : valid(false) {}

    node(int _address, int _data, int _next) : address(_address), data(_data), next(_next), valid(false) {}
};

void solution() {

    int head, size, K;
    cin >> head >> size >> K;

    // 输入节点数据
    node list[100000];
    int cur, data, next;
    for (int i = 0; i < size; i++) {
        cin >> cur >> data >> next;
        list[cur] = node(cur, data, next);
    }

    // 标记有效节点；v1,v2,v3存储小于0，0到K，大于K的节点
    vector<node> v1, v2, v3;
    int p = head;
    while (p != -1) {
        list[p].valid = true;
        if (list[p].data < 0) {
            v1.push_back(list[p]);
        } else if (list[p].data <= K) {
            v2.push_back(list[p]);
        } else {
            v3.push_back(list[p]);
        }
        p = list[p].next;
    }

    cout.fill('0');
    // 输出一个节点
    int count = (int) v1.size() + (int) v2.size() + (int) v3.size(), j = 0; // count表示有效节点的总数，j表示已经输出的节点个数
    if (count == 1) {
        if (v1.size() != 0) {
            cout << setw(5) << v1[0].address << " " << v1[0].data << " " << -1 << endl;
            return;
        }
        if (v2.size() != 0) {
            cout << setw(5) << v2[0].address << " " << v2[0].data << " " << -1 << endl;
            return;
        }
        if (v3.size() != 0) {
            cout << setw(5) << v3[0].address << " " << v3[0].data << " " << -1 << endl;
            return;
        }
    }

    // 输出多个节点
    for (int i = 0; i < v1.size(); i++) {
        if (j == count - 1) {
            cout << setw(5) << v1[i].address << endl << setw(5) << v1[i].address << " " << v1[i].data << " " << -1
                 << endl;
            j++;
        } else if (j == 0) {
            cout << setw(5) << v1[i].address << " " << v1[i].data << " ";
            j++;
        } else {
            cout << setw(5) << v1[i].address << endl << setw(5) << v1[i].address << " " << v1[i].data << " ";
            j++;
        }
    }
    for (int i = 0; i < v2.size(); i++) {
        if (j == count - 1) {
            cout << setw(5) << v2[i].address << endl << setw(5) << v2[i].address << " " << v2[i].data << " " << -1
                 << endl;
            j++;
        } else if (j == 0) {
            cout << setw(5) << v2[i].address << " " << v2[i].data << " ";
            j++;
        } else {
            cout << setw(5) << v2[i].address << endl << setw(5) << v2[i].address << " " << v2[i].data << " ";
            j++;
        }
    }
    for (int i = 0; i < v3.size(); i++) {
        if (j == count - 1) {
            cout << setw(5) << v3[i].address << endl << setw(5) << v3[i].address << " " << v3[i].data << " " << -1
                 << endl;
            j++;
        } else if (j == 0) {
            cout << setw(5) << v3[i].address << " " << v3[i].data << " ";
            j++;
        } else {
            cout << setw(5) << v3[i].address << endl << setw(5) << v3[i].address << " " << v3[i].data << " ";
            j++;
        }
    }

}

int main() {
    /**
     * 测试用例：
     * 00100 9 10 23333 10 27777 00000 0 99999 00100 18 12309 68237 -6 23333 33218 -4 00000 48652 -2 -1 99999 5 68237 27777 11 48652 12309 7 33218
     * 期待输出：
     * 33218 -4 68237
     * 68237 -6 48652
     * 48652 -2 12309
     * 12309 7 00000
     * 00000 0 99999
     * 99999 5 23333
     * 23333 10 00100
     * 00100 18 27777
     * 27777 11 -1
     */
    solution();
    return 0;
}