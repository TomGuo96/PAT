//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

void solution() {
    int hash[100001] = {}; // 表示硬币出现次数

    int size, bill;
    cin>>size>>bill;

    for (int i = 0; i < size; i++) {
        int x;
        cin>>x;
        hash[x]++;
    }

    for (int i = 1; i <= bill / 2; i++) {

        if (hash[i] > 0) {
            hash[i]--;
            if (hash[bill - i] > 0) {
                cout<<i<<" "<<bill - i<<endl;
                return 0;
            }
        }
    }
    cout<<"No Solution"<<endl;
}

int main() {
    solution();
    return 0;
}