//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>
#include <iomanip>

using namespace std;

const string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

void solution() {

    string str[4];
    cin>>str[0]>>str[1]>>str[2]>>str[3];
    int i;
    for (i = 0; i < min(str[0].length(), str[1].length()); i++) {
        if (str[0][i] == str[0][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
            cout<<week[str[0][i] - 'A']<<" ";
            break;
        }
    }
    cout.fill('0');
    for (int j = i + 1; j < min(str[0].length(), str[1].length()); j++) {
        if (str[0][j] == str[1][j] && ((str[0][j] >= 'A' && str[0][j] <= 'N') || isdigit(str[0][j]))) {
            if (str[0][j] >= 'A' && str[0][j] <= 'N') {
                cout<<setw(2)<<str[0][j] - 'A' + 10<<":";
                break;
            }
            if (isdigit(str[0][j])) {
                cout<<setw(2)<<str[0][j] - '0'<<":";
                break;
            }
        }
    }

    for (i = 0; i < min(str[2].length(), str[3].length()); i++) {
        if (str[2][i] == str[3][i] && isalpha(str[2][i])) {
            cout<<setw(2)<<i<<endl;
            break;
        }
    }

}

int main() {
    /**
     * 测试用例：
     * 3485djDkxh4hhGE 2984akDfkkkkggEdsb  s&hgsfdk d&Hyscvnm
     * 期待结果：
     * THU 14:04
     */
    solution();
    return 0;
}