//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>

using namespace std;

void solution() {
    int size;
    cin>>size;

    for (int i = 1; i <= size; i++) {
        long long x, y, z, sum;
        cin >> x >> y >> z;
        sum = x + y;

        if (x > 0 && y > 0 && sum <= 0) {
            cout<<"Case #"<<i<<": true"<<endl;
        } else if (x < 0 && y < 0 && sum > 0) {
            cout<<"Case #"<<i<<": false"<<endl;
        } else if (sum > z) {
            cout<<"Case #"<<i<<": true"<<endl;
        } else {
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }
}

int main() {
    /**
     * 测试用例：
     * 3 1 2 3 2 3 4 9223372036854775807 -9223372036854775808 0
     * 期待结果：
     * Case #1: false
     * Case #2: true
     * Case #3: false
     */
    solution();
    return 0;
}