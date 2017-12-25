//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int res[1001] = {}; // 结果数组，res[i]表示i次方项的系数
    int x, n;
    int count; // 记录非零项的个数

    while(cin>>x>>n) {

        if (n == 0)
            break;

        res[n - 1] = n * x;
        count++;
    }
    if (count == 0) {
        cout<<"0 0\n";
        return;
    }
    int out = 0; // 记录已经输出的项数
    for (int i = 1000; i >= 0; i--) {
        if (res[i] != 0 && out < count - 1) {
            cout<<res[i]<<" "<<i<<" ";
            out++;
        } else if (res[i] != 0 && out == count - 1) {
            cout<<res[i]<<" "<<i<<endl;
            return;
        }
    }

}

int main() {
    solution();
    return 0;
}