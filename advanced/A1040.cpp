//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    bool dp[1000][1000];
    fill(dp[0], dp[0] + 1000 * 1000, false); // 初始化dp数组
    string s;
    getline(cin, s);
    int len = (int)s.length();
    int ret = 1;

    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
        if (i < len - 1) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ret = 2;
            }
        }
    }

    for (int l = 3; l <= len; l++) {
        for (int i = 0; i + l - 1 < len; i++) {
            int j = i + l - 1; // 字串的右端点
            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ret = l;
            }
        }
    }

    cout<<ret<<endl;

}

int main() {
    /**
     * case: Is PAT&TAP symmetric?
     * result: 11
     */
    solution();
    return 0;
}