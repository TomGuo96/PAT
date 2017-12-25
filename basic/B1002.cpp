#include <iostream>

using namespace std;

// 获取个位数字
int getLastNumber(long int n){
    if(n < 10)
        return n;
    return n - (n / 10) * 10;
}

// 根据数字添加字符
void addChar(int n, string &str){

    if(str != "")
        str = " " + str;
    switch (n) {
        case 0:
            str = "零" + str;
            break;
        case 1:
            str = "一" + str;
            break;
        case 2:
            str = "二" + str;
            break;
        case 3:
            str = "三" + str;
            break;
        case 4:
            str = "四" + str;
            break;
        case 5:
            str = "五" + str;
            break;
        case 6:
            str = "六" + str;
            break;
        case 7:
            str = "七" + str;
            break;
        case 8:
            str = "八" + str;
            break;
        case 9:
            str = "九" + str;
            break;
        default:
            str = "默认" + str;
    }

}

void solution(){
    long int n;
    cin>>n;

    // 求出所有位数之和plus
    long int plus = 0;
    while(n != 0){
        plus += getLastNumber(n);
        n /= 10;
    }

    string rtn = "";
    while(plus != 0){
        int k = getLastNumber(plus);
        plus /= 10;
        addChar(k, rtn);
    }

    cout<<rtn<<endl;
}

int main() {
    solution();
    return 0;
}