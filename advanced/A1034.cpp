//
// Created by Tom Guo on 23/10/2017.
//

#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2000;
const int INF = INT_MAX;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;

int G[MAXN][MAXN] = {}, weight[MAXN] = {};
// 边数n，下限k，总人数numPerson
int n, k, numPerson = 0;
bool vis[MAXN] = {false};

// DFS函数访问单个连通块，nowVisit为当前访问的编号
void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
    numMember++;
    vis[nowVisit] = true;
    if (weight[nowVisit] > weight[head])
        head = nowVisit;
    for (int i = 0; i < numPerson; i++) {
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if (!vis[i])
                DFS(i, head, numMember, totalValue);
        }
    }
}

void DFSTravel() {
    for (int i = 0; i < numPerson; i++) {
        if (!vis[i]) {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(const string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

void solution() {

    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTravel();
    cout << Gang.size() << endl;
    for (map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++)
        cout << it->first << " " << it->second << endl;
    }

int main() {
    /**
     * 测试用例：
     * 8 59 AAA BBB 10 BBB AAA 20 AAA CCC 40 DDD EEE 5 EEE DDD 70 FFF GGG 30 GGG HHH 20 HHH FFF 10
     * 期待输出：
     * 2
     * AAA 3
     * GGG 3
     */
    solution();
    return 0;
}