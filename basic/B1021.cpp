//
// Created by Tom Guo on 26/10/2017.
//

#include <iostream>
#include <iomanip>

using namespace std;

void solution() {

    string s;
    cin>>s;

    int count[10] = {0};
    for (int i = 0; i < s.length(); i++)
        count[s[i] - '0']++;

    for (int i = 0; i < 10; i++)
        if (count[i] != 0)
            cout<<i<<":"<<count[i]<<endl;

}

int main() {
    /**
     * 测试用例：
     * 100311
     * 期待结果：
     * 0:2
     * 1:3
     * 3:1
     */
    solution();
    return 0;
}