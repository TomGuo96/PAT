//
// Created by Tom Guo on 11/12/2017.
//

#include <iostream>
#include <vector>

using namespace std;

// 将string类型的数字转换为vector类型
vector<int> convert(string str) {

    vector<int> res;
    for (int i = str.size() - 1; i >= 0; i--)
        res.push_back(str[i] - '0');
    return res;

}


// 重载<<运算符
ostream &operator<<(ostream &os, const vector<int> &vec) {

    for (int i = vec.size() - 1; i >= 0; i--)
        os << vec[i];
    return os;

}

// 判断是否为回文数字
bool isPalin(const vector<int> &vec) {

    if (vec.size() == 1)
        return true;

    for (int i = 0, len = vec.size(); i < len / 2; i++) {
        if (vec[i] != vec[len - i - 1])
            return false;
    }
    return true;

}

// 对两个大数求和
vector<int> add(const vector<int> &vec1, const vector<int> &vec2) {

    vector<int> res;
    int len = min(vec1.size(), vec2.size());
    int carry = 0;
    int sum;
    for (int i = 0; i < len; i++) {
        sum = vec1[i] + vec2[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0)
        res.push_back(carry);
    return res;

}

void solution() {

    string strOri;
    cin >> strOri;
    vector<int> ori = convert(strOri);

    if (isPalin(ori)) {
        cout << ori << " is a palindromic number." << endl;
        return;
    }

    for (int i = 0; i < 10; i++) {

        vector<int> rev = ori;
        reverse(rev.begin(), rev.end());

        vector<int> sum = add(ori, rev);

        cout << ori << " + " << rev << " = " << sum << endl;

        if (isPalin(sum)) {
            cout << sum << " is a palindromic number." << endl;
            return;
        }

        ori = sum;

    }

    cout << "Not found in 10 iterations." << endl;
    return;

}

int main() {
    solution();
    return 0;
}