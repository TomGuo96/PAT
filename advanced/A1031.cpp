#include <iostream>

using namespace std;

void solution(){

    string str;
    cin>>str;

    // 字符串总长度
    int len = (int)str.length();
    // 输出总行数len
    int lines = 0;
    if(len % 3 == 0){
        lines = len / 3;
    } else {
        lines = len / 3 + 1;
    }
    // 前len-1行字符间的空格数
    int spaces = len - lines * 2;

    // 具体输出
    for(int i = 0; i < lines - 1; i++){
        cout<<str[i];
        for(int j = 0; j < spaces; j++)
            cout<<" ";
        cout<<str[len - i - 1]<<endl;
    }
    for(int j = lines - 1; j <= lines + spaces; j++){
        cout<<str[j];
    }
    cout<<endl;

}

int main() {
    /**
     * 情况一：len%3 == 0
     * 例如：123456
     * 情况二：len%3 != 0
     * 例如：12345678
     */
    solution();
    return 0;
}