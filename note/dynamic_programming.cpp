//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>
#include <algorithm>

using namespace std;

/****************
 * 最大连续子序列和
 ****************/

/*
 * 输入数据：
 * 6 -2 11 -4 13 -5 -2
 * 期待输出：
 * 20
 */
/*
const int MAXN = 10000;

int seq[MAXN], dp[MAXN]; // seq存放序列，dp存放以seq[i]结尾的连续序列的最大和

int main() {

    int size;
    cin>>size;

    for (int i = 0; i < size; i++)
        cin>>seq[i];

    // 边界
    dp[0] = seq[0];

    for (int i = 1; i < size; i++)
        //状态转移方程
        dp[i] = max(seq[i], dp[i - 1] + seq[i]);

    int j = 0;
    for (int i = 1; i < size; i++) {
        if (dp[i] > dp[j])
            j = i;
    }

    cout<<dp[j]<<endl;

    return 0;
}
*/

/******************
 * 最长不下降子序列和
 ******************/

/*
 * 输入数据：
 * 8 1 2 3 -9 3 9 0 11
 * 期待输出：
 * 6
 */
/*
const int N = 100;

int seq[N], dp[N];

int main() {

    int size;
    cin>>size;

    for (int i = 1; i <= size; i++)
        cin>>seq[i];

    int ans = -1; // 记录最大的dp[i]
    for (int i = 1; i <= size; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (seq[i] >= seq[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}
*/

/**************
 * 最长公共子序列
 **************/

//#include <cstdio>
//#include <cstring>
//#include <algorithm>

//using namespace std;

/*
 * 测试用例：
 * sadstory adminsorry
 * 期待结果：
 * 6
 */
/*
const int N = 100;

char str1[N], str2[N];
int dp[N][N];

int main() {

    gets(str1 + 1);
    gets(str2 + 1);
    int len1 = (int)strlen(str1 + 1);
    int len2 = (int)strlen(str2 + 1);

    // 边界
    for (int i = 0; i <= len1; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= len2; i++)
        dp[0][i] = 0;

    // 状态转移方程
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[len1][len2]);
}
 */

/************
 * 最长回文字串
 ************/

/*
 * 测试用例：
 * atzjujzta
 * 期待结果：
 * 9
 */
/*
const int MAXN = 1000;

string s;
int dp[MAXN][MAXN];

int main() {

    cin>>s;

    int len = (int)s.length();
    int ans = 1;
    memset(dp, 0, sizeof(dp)); // dp数组初始化为0

    // 边界
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if (i < len - 1) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
                ans = 2;
            }
        }
    }

    // 状态转移方程
    for (int L = 3; L <= len; L++) {
        for (int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1; // 字串的右端点
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
*/
