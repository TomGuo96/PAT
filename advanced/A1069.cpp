#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool cmp(int a , int b){
    return a > b;
}

void numToArray(int num, int str[]){
    for(int i = 0; i < 4; i++){
        str[i] = num - num / 10 * 10;
        num /= 10;
    }
}

int toMin(int num[]){
    int ret = 0;
    int base = 1;
    for(int i = 0; i < 4; i++){
        ret += num[i] * base;
        base *= 10;
    }
    return ret;
}

int toMax(int num[]){
    int ret = 0;
    int base = 1;
    for(int i = 3; i >= 0; i--){
        ret += num[i] * base;
        base *= 10;
    }
    return ret;
}

void solution(){
    int x, num[4] = {0}, max, min, minus;
    cin>>x;
    numToArray(x, num);
    cout.fill('0');
    do {
        sort(num, num + 4, cmp);
        max = toMax(num);
        min = toMin(num);
        minus = max - min;
        cout<<setw(4)<<max<<" - "<<setw(4)<<min<<" = "<<setw(4)<<minus<<endl;
        numToArray(minus, num);
    } while(minus != 0 && minus != 6174);
}

int main() {
    /**
     * 测试用例：
     * 6767
     * 期待结果：
     * 7766 - 6677 = 1089
     * 9810 - 0189 = 9621
     * 9621 - 1269 = 8352
     * 8532 - 2358 = 6174
     */
    solution();
    return 0;
}