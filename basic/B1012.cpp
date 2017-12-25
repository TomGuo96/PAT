//
// Created by Tom Guo on 26/10/2017.
//

#include <iostream>
#include <iomanip>

using namespace std;

void solution() {

    int size;
    cin>>size;

    int ret[5] = {0};
    bool valid[5] = {0};
    int sign = 1, count = 0;
    for (int i = 0; i < size; i++) {
        int num;
        cin>>num;
        if (num % 5 == 0) {
            if (num % 2 == 0) {
                ret[0] += num;
                valid[0] = true;
            }
        } else if (num % 5 == 1) {
            ret[1] += sign * num;
            sign = -sign;
            valid[1] = true;
        } else if (num % 5 == 2) {
            ret[2]++;
            valid[2] = true;
        } else if (num % 5 == 3) {
            ret[3] += num;
            count++;
            valid[3] = true;
        } else {
            ret[4] = ret[4] > num ? ret[4] : num;
            valid[4] = true;
        }
    }
    if (valid[0])
        cout<<ret[0]<<" ";
    else cout<<"N ";
    if (valid[1])
        cout<<ret[1]<<" ";
    else cout<<"N ";
    if (valid[2])
        cout<<ret[2]<<" ";
    else
        cout<<"N ";
    if (valid[3])
        cout<<fixed<<setprecision(1)<<(double)ret[3] / count<<" ";
    else
        cout<<"N ";
    if (valid[4])
        cout<<ret[4]<<endl;
    else
        cout<<"N"<<endl;

}

int main() {
    /**
     * 测试用例：
     * 13 1 2 3 4 5 6 7 8 9 10 20 16 18
     * 期待结果：
     * 30 11 2 9.7 9
     */
    solution();
    return 0;
}