//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

void solution() {

    int size;
    cin>>size;

    vector<string> vi;
    for (int i = 0; i < size; i++) {
        string str;
        cin>>str;
        vi.push_back(str);
    }

    sort(vi.begin(), vi.end(), cmp);

    string res; // 结果数组
    for (int i = 0; i < size; i++)
        res += vi[i];

    // 去除前导零
    while (res.size() != 1 && res[0] == '0')
        res.erase(res.begin());

    cout<<res<<endl;

}

int main() {
    solution();
    return 0;
}