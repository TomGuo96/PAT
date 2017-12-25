//
// Created by Tom Guo on 16/11/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution() {

    int size, p;
    cin>>size>>p;

    vector<long long> vi;
    for (int i = 0; i < size; i++) {
        long long x;
        cin>>x;
        vi.push_back(x);
    }

    sort(vi.begin(), vi.end());

    int res = 1;
    for (int i = 0; i < size; i++) {
        int j = upper_bound(vi.begin() + i + 1, vi.begin() + size, vi[i] * p) - vi.begin();
        res = max(res, j - i);
    }
    cout<<res<<endl;

}

int main() {
    solution();
    return 0;
}