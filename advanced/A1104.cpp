//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int size;
    cin>>size;

    double res = 0;
    for (int i = 1; i <= size; i++) {
        double x;
        cin>>x;
        res += x * i * (size + 1 - i);
    }
    cout<<fixed<<setprecision(2)<<res<<endl;

}

int main() {
    solution();
    return 0;
}