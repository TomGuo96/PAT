#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 100000;

bool is_prime(int n) {
    if (n == 1)
        return false;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}

int prime[MAXN], pNum = 0;

// 求素数表
void find_prime() {
    for (int i = 1; i < MAXN; i++) {
        if (is_prime(i))
            prime[pNum++] = i;
    }
}

struct factor {
    int x, cnt;
} fac[10];

void solution() {

    find_prime();
    int n, num = 0;
    cin >> n;
    if (n == 1) {
        cout << "1=1\n";
        return;
    }
    cout << n << "=";
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
        if (n % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while (n % prime[i] == 0) {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
        if (n == 1)
            break;
    }
    if (n != 1) {
        fac[num].x = n;
        fac[num++].cnt = 1;
    }
    for (int i = 0; i < num; i++) {
        if (i > 0)
            cout << "*";
        cout << fac[i].x;
        if (fac[i].cnt > 1)
            cout << "^" << fac[i].cnt;
    }
}


int main() {
    /**
     * 测试用例：
     * 97532468
     * 期待输出：
     * 97532468=2^2*11*17*101*1291
     */
    solution();
    return 0;
}