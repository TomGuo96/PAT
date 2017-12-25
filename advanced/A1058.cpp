//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int x1, y1, z1, x2, y2, z2;

    (cin>>x1).get();
    (cin>>y1).get();
    cin>>z1;
    (cin>>x2).get();
    (cin>>y2).get();
    cin>>z2;

    int carry = 0, sum = 0;

    sum = z1 + z2;
    z1 = sum % 29;
    carry = sum / 29;

    sum = y1 + y2 + carry;
    y1 = sum % 17;
    carry = sum / 17;

    x1 += x2 + carry;

    cout<<x1<<"."<<y1<<"."<<z1<<endl;

}

int main() {
    solution();
    return 0;
}