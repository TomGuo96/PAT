//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

/* 一个报错，找不到原因 */
// TODO
int solution() {

    int size;
    cin>>size;
    cin.get();

    int shortest = 257; // 表示最短字符串的长度
    string str[size];
    for (int i = 0; i < size; i++) {
        getline(cin, str[i]);
        shortest = min(shortest, (int)str[i].size());
    }

    int res = 0; // 表示相同部分的长度
    for (int i = 0; i < shortest; i++) {

        // 检测倒数第i位是否相同
        bool same = true;
        char ch = str[0][str[0].size() - 1 - i]; // 待检测字符

        for (int j = 0; j < size; j++) {
            int len = (int)str[j].size();
            if (str[j][len - i - 1] != ch && str[j][len - i - 1] != ' ') {
                same = false;
                break;
            }
        }
        if (!same) {
            res = i;
            break;
        }
    }
    if (!res)
        cout<<"nai\n";
    else
        cout<<str[0].substr(str[0].size() - res)<<endl;

}

int main() {
    solution();
    return 0;
}