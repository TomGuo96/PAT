//
// Created by Tom Guo on 11/12/2017.
//

#include <iostream>

using namespace std;

const string mars[2][13] = {
        {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
        {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};

bool isEarth(string str) {
    return str[0] >= '0' && str[0] <= '9';
}

int convertToInt(string str) {

    int base = 1;
    int res = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        res += (str[i] - '0') * base;
        base *= 10;
    }
    return res;

}

string convertToMars(string str) {

    int num = convertToInt(str);
    int higher = num / 13;
    int lower = num % 13;
    if (higher) {
        if (lower)
            return mars[1][higher] + " " + mars[0][lower];
        else
            return mars[1][higher];
    } else
        return mars[0][lower];

}

int convertToEarth(string str) {

    int res = 0;
    if (str.find(' ') != string::npos) {
        int pos = str.find(' ');
        string higher = str.substr(0, pos);
        string lower = str.substr(pos + 1);

        for (int i = 0; i < 13; i++) {
            if (higher == mars[1][i])
                res += 13 * i;
            if (lower == mars[0][i])
                res += i;
        }
        return res;
    } else {
        for (int i = 0; i < 13; i++) {
            if (str == mars[1][i])
                res += 13 * i;
            if (str == mars[0][i])
                res += i;
        }
        return res;
    }

}

void solution() {

    int lines;
    cin >> lines;
    cin.get();

    string str;
    for (int i = 0; i < lines; i++) {
        getline(cin, str);
        if (isEarth(str))
            cout << convertToMars(str) << endl;
        else
            cout << convertToEarth(str) << endl;
    }

}

int main() {
    solution();
    return 0;
}