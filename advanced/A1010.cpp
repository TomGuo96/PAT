#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int Map[256];

// 将radix进制的str转换为10进制，ceil为上界
long long convertTo10(string str, long long radix, long long ceil) {

    long long res = 0;
    long long weight = 1;
    auto len = str.size();
    for (int i = len - 1; i >= 0; i--) {
        res += Map[str[i]] * weight;
        weight *= radix;
        // 溢出或者超过进制
        if (res < 0 || res > ceil)
            return -1;
    }
    return res;

}

int cmp(string str, long long radix, long long x) {

    auto len = str.size();
    long long num = convertTo10(str, radix, x);
    // 溢出一定大于
    if (num < 0)
        return 1;
    if (x > num)
        return -1;
    else if (x == num)
        return 0;
    else
        return 1;

}

int findeMaxDigit(string str) {
    int res = -1;
    auto len = str.size();
    for (int i = 0; i < len; i++) {
        if (Map[str[i]] > res) {
            res = Map[str[i]];
        }
    }
    return res + 1; // 最大的数位是res，说明进制的底线为res+1
}

long long binarySearch(string str, long long l, long long r, long long num) {

    long long mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        int flag = cmp(str, mid, num); // 将mid进制的str转换为10进制后与num比较
        if (flag == 0)
            return mid;
        else if (flag == -1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;

}

void solution() {

    // 将0-9，a-z映射到0-35
    for (char c = '0'; c <= '9'; c++)
        Map[c] = c - '0';
    for (char c = 'a'; c <= 'z'; c++)
        Map[c] = c - 'a' + 10;

    string str1, str2, temp;
    int tag, radix;
    cin>>str1>>str2>>tag>>radix;
    if (tag == 2)
        swap(str1, str2);
    long long x = convertTo10(str1, radix, LLONG_MAX);
    long long floor = findeMaxDigit(str2); // 找到str2中数位最低的，作为二分查找的下界
    long long ceil = max(floor, x) + 1; // 上界
    long long res = binarySearch(str2, floor, ceil, x);
    if (res == -1)
        cout<<"Impossible\n";
    else
        cout<<res;

}

int main() {
    solution();
}
