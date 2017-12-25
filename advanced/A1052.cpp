#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct node {
    int address;
    int next;
    int data;
    bool valid;

    node() {
        next = -1;
        data = 0;
        valid = false;
    }
};

bool cmp(node a, node b) {
    return a.data < b.data;
}

void solution() {

    int size, head;
    cin >> size >> head;

    node arr[100000];
    for (int i = 0; i < size; i++) {
        int address;
        cin >> address;
        cin >> arr[address].data >> arr[address].next;
        arr[address].address = address;
    }

    // 遍历一遍链表，标记有效节点
    int p = head, count;
    while (p != -1) {
        count++;
        arr[p].valid = true;
        p = arr[p].next;
    }

    // 排序
    sort(arr, arr + 100000, cmp);

    // 找到第一个有效节点
    int k = 0, cnt = 0;
    while (!arr[k].valid) {
        k++;
    }

    cout << count << " ";
    cout.fill('0');
    while (true) {
        if (cnt == count)
            break;
        if (arr[k].valid) {
            cout << setw(5) << arr[k].address << endl << setw(5) << arr[k].address << " " << arr[k].data << " ";
            cnt++;
        }
        k++;
    }
    cout << -1 << endl;

}

int main() {
    /**
     * 测试用例：
     * 5 00001 11111 100 -1 00001 0 22222 33333 100000 11111 12345 -1 33333 22222 1000 12345
     * 期待结果：
     * 5 12345
     * 12345 -1 00001
     * 00001 0 11111
     * 11111 100 22222
     * 22222 1000 33333
     * 33333 100000 -1
     */
    solution();
    return 0;
}