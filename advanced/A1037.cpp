//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution() {

    vector<int> v1, v2;

    int m, n;
    cin>>m;
    for (int i = 0; i < m; i++) {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0, j, res = 0;
    while (i < n && i < m && v1[i] < 0 && v2[i] < 0) {
        res += v1[i] * v2[i];
        i++;
    }
    i = m - 1;
    j = n - 1;
    while (i >= 0 && j >= 0 && v1[i] > 0 && v2[j] > 0) {
        res += v1[i] * v2[j];
        i--;
        j--;
    }
    cout<<res<<endl;

}

int main() {
    solution();
    return 0;
}