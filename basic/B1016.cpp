//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

int getP(int x, int d) {

    int res = 0;
    int base = 1;
    while (x > 0) {
        int mod = x % 10;
        x /= 10;
        if (mod == d) {
            res += base * d;
            base *= 10;
        }

    }
    return res;
}

void solution(){

    int x, y, Dx, Dy;
    cin>>x>>Dx>>y>>Dy;

    cout<<getP(x, Dx) + getP(y, Dy)<<endl;

}

int main() {
    /**
     * 测试用例：
     * 3862767 6 13530293 3
     * 期待结果：
     * 399
     */
    solution();
    return 0;
}