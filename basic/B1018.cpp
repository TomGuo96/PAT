//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int size;
    cin>>size;

    int winTimes[2] = {}; // 两人获胜次数
    int even = 0; // 记录平局次数
    int winBy[2][3] = {}; // 记录靠什么获胜，顺序为B，C，J
    for (int i = 0; i < size; i++) {
        char x, y;
        cin>>x>>y;

        if (x == 'C') {
            if (y == 'J') {
                winTimes[0]++;
                winBy[0][1]++;
            } else if (y == 'B') {
                winTimes[1]++;
                winBy[1][0]++;
            } else {
                even++;
            }
        } else if (x == 'J') {
            if (y == 'B') {
                winTimes[0]++;
                winBy[0][2]++;
            } else if (y == 'C') {
                winTimes[1]++;
                winBy[1][1]++;
            } else {
                even++;
            }
        } else if (x == 'B') {
            if (y == 'C') {
                winTimes[0]++;
                winBy[0][0]++;
            } else if (y == 'J') {
                winTimes[1]++;
                winBy[1][2]++;
            } else {
                even++;
            }
        }
    }


    cout<<winTimes[0]<<" "<<even<<" "<<winTimes[1]<<endl;
    cout<<winTimes[1]<<" "<<even<<" "<<winTimes[0]<<endl;

    int max = winBy[0][0], p = 0;
    for (int i = 1; i < 3; i++) {
        if (winBy[0][i] > max) {
            max = winBy[0][i];
            p = i;
        }
    }
    if (p == 0)
        cout<<"B ";
    else if (p == 1)
        cout<<"C ";
    else
        cout<<"J ";

    max = winBy[1][0];
    p = 0;
    for (int i = 1; i < 3; i++) {
        if (winBy[1][i] > max) {
            max = winBy[1][i];
            p = i;
        }
    }
    if (p == 0)
        cout<<"B\n";
    else if (p == 1)
        cout<<"C\n";
    else
        cout<<"J\n";

}

int main() {
    solution();
    return 0;
}