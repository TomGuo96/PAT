//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int size;
    cin>>size;

    for (int i = 1; i <= size; i++) {
        long long x, y, z;
        cin>>x>>y>>z;

        if (x + y > z) {
            cout<<"Case #"<<i<<": true"<<endl;
        } else {
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }

}

int main() {
    solution();
    return 0;
}