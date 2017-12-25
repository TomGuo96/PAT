//
// Created by Tom Guo on 11/12/2017.
//

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

void solution() {

    int size;
    cin >> size;

    unordered_map<int, int> mp; // 伴侣的查找表
    int couple1, couple2;
    for (int i = 0; i < size; i++) {
        cin >> couple1 >> couple2;
        mp.insert(make_pair(couple1, couple2));
        mp.insert(make_pair(couple2, couple1));
    }

    vector<int> single; // 单身的人
    set<int> guest;
    int g;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> g;
        guest.insert(g);
    }

    for (auto it = guest.begin(); it != guest.end(); it++) {
        if (mp.find(*it) != mp.end()) {
            if (guest.find(mp.find(*it)->second) == guest.end())
                single.push_back(*it);
        } else
            single.push_back(*it);
    }

    cout.fill('0');
    cout << single.size() << endl;
    for (int i = 0; i < single.size(); i++) {
        if (i < single.size() - 1)
            cout << setw(5) << single[i] << " ";
        else
            cout << setw(5) << single[i] << endl;
    }

}

int main() {
    solution();
    return 0;
}