//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int pos[100001]; // pos[i]表示数字i所在的位置

    int size = 0;
    cin>>size;
    int wrong = size - 1; // wrong表示不在正确位置的个数(0除外)

    for (int i = 0; i < size; i++) {
        int x;
        cin>>x;
        pos[x] = i;
        if (x == i && x != 0)
            wrong--;
    }

    int res = 0; // 交换次数
    int min_wrong = 1; // 表示不在正确位置数字的最小值
    while (wrong > 0) {

        // 如果0在正确位置上
        if (pos[0] == 0) {
            while (min_wrong < size) {
                if (pos[min_wrong] != min_wrong) {
                    swap(pos[0], pos[min_wrong]);
                    res++;
                    break;
                }
                min_wrong++;
            }
        }
        // 0不在正确位置上
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            res++;
            wrong--;
        }
    }
    cout<<res<<endl;

}

int main() {
    solution();
    return 0;
}