//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& vec) {
    int size = (int)vec.size();
    for (int i = 0; i < size; i++) {
        cout<<vec[i];
        if (i < size - 1)
            cout<<" ";
    }
    cout<<endl;
}

bool insertionSort(vector<int>& origin, vector<int>& target, vector<int>& result) {

    bool flag = false; // 记录过程中是否与所给数组相同

    int size = (int)origin.size();

    result = origin;
    for (int i = 1; i < size; i++) {

        // 若不是初始序列，并且相同
        if (i != 1 && result == target)
            flag = true;

        // 插入排序
        int tmp = result[i], j = i;
        while (j > 0 && result[j - 1] > tmp) {
            result[j] = result[j - 1];
            j--;
        }
        result[j] = tmp;

        if (flag)
            return true;
    }
    return false;
}

void mergeSort(vector<int>& origin, vector<int>& target, vector<int>& result) {

    bool flag = false;
    int size = (int)origin.size();

    // 归并排序
    result = origin;
    for (int step = 2; step / 2 <= size; step *= 2) {

        if (step != 2 && result == target)
            flag = true;

        for (int i = 0; i < size; i += step)
            sort(result.begin() + i, result.begin() + min(i + step, size));

        if (flag) {
            printArray(result);
            return;
        }
    }
}

void solution() {

    int size;
    cin>>size;

    vector<int> vec;
    for (int i = 0; i < size; i++) {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<int> target;
    for (int i = 0; i < size; i++) {
        int x;
        cin>>x;
        target.push_back(x);
    }

    vector<int> result;
    if (insertionSort(vec, target, result)) {
        cout<<"Insertion Sort"<<endl;
        printArray(result);
    } else {
        cout<<"Merge Sort"<<endl;
        mergeSort(vec, target, result);
    }

}


int main() {
    solution();
    return 0;
}