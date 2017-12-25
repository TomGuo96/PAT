//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>

using namespace std;

int solution() {

    int size, offset;
    cin>>size>>offset;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin>>arr[i];

    int head = 0;
    for (int i = 0; i < offset; i++) {
        if (head == 0) {
            head = size - 1;
        } else {
            head--;
        }
    }

    int count = 0; // 记录已经输出的元素个数
    for (int i = head; i < size; i++) {
        if (count < size - 1) {
            cout<<arr[i]<<" ";
            count++;
        } else {
            cout<<arr[i]<<endl;
            return 0;
        }
    }
    for (int i = 0; i < head; i++) {
        if (count < size - 1) {
            cout<<arr[i]<<" ";
            count++;
        } else {
            cout<<arr[i]<<endl;
            return 0;
        }
    }

}

int main() {
    solution();
    return 0;
}