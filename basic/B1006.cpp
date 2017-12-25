//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int number;
    cin>>number;

    // num数组存储个十白位的数字
    int num[3];
    for (int i = 0; i < 3; i++) {
        num[i] = number - number / 10 * 10;
        number /= 10;
    }

    // 根据题意输出
    for(int i = 0; i < num[2]; i++)
        cout<<"B";
    for(int i = 0; i < num[1]; i++)
        cout<<"S";
    for(int i = 0; i < num[0]; i++)
        cout<<i + 1;
    cout<<endl;

}

int main() {
    /**
     * case: 123
     * result: BSS123
     */
    solution();
    return 0;
}