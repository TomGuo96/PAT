#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct ndoe {
    int weight;
    vector<int> child;
} Node[MAXN];

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}

int N, m, S; // 记录节点数，边数，给定的和
int path[MAXN]; // 记录路径

void DFS(int index, int numNode, int sum) {
    if (sum > S)
        return;
    if (sum == S) {
        if (Node[index].child.size() != 0)
            return;
        for (int i = 0; i < numNode; i++) {
            cout << Node[path[i]].weight;
            if (i < numNode - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    for (int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}

void solution() {
    cin >> N >> m >> S;
    for (int i = 0; i < N; i++)
        cin >> Node[i].weight;
    int id, k, child;
    for (int i = 0; i < m; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> child;
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);
}

int main() {
    /**
     * 测试用例：
     * 20 9 24
     * 10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
     * 00 4 01 02 03 04
     * 02 1 05
     * 04 2 06 07
     * 03 3 11 12 13
     * 06 1 09
     * 07 2 08 10
     * 16 1 15
     * 13 3 14 16 17
     * 17 2 18 19
     * 期待结果：
     * 10 5 2 7
     * 10 4 10
     * 10 3 3 6 2
     * 10 3 3 6 2
     */
    solution();
    return 0;
}