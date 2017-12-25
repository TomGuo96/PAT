//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>

using namespace std;

void solution() {
    int num;
    cin>>num;

    int weight = 1, res = 0;
    int left, now, right;

    while (num / weight != 0) {
        left = num / (weight * 10);
        now = num / weight % 10;
        right = num % weight;
        if (now == 0)
            res += left * weight;
        else if (now == 1)
            res += left * weight + right + 1;
        else
            res += (left + 1) * weight;
        weight *= 10;
    }
    cout<<res<<endl;
}

int main() {
    solution();
    return 0;
}