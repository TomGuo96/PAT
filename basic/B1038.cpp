//
// Created by Tom Guo on 25/12/2017.
//

#include <iostream>
#include <vector>

using namespace std;

void solution() {

    int size, score;
    cin>>size;

    vector<int> record(101, 0); // record[i]表示分数为i的人数
    for (int i = 0; i < size; ++i) {
        cin>>score;
        record[score] += 1;
    }

    cin>>size>>score;
    cout<<record[score];
    for (int i = 0; i < size - 1; ++i) {
        cin>>score;
        cout<<" "<<record[score];
    }
    cout<<endl;

}

int main() {
    solution();
    return 0;
}