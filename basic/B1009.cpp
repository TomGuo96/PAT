#include <iostream>

using namespace std;

// 从end位置向前找到第一个空格的位置，没有则返回-1
int findSpace(string str, int end){

    int i = end;
    while(str[i] != ' ' && i >= 0)
        i--;
    return i;

}

// 输出两个位置间（包含）的字符串
void outputWord(string str, int start, int end){
    for(int i = start; i <= end; i++)
        cout<<str[i];
}

void solution(){

    string str;
    getline(cin, str);

    int begin, end = str.length() - 1;
    while(true){
        if(end != str.length() - 1)
            cout<<" ";
        begin = findSpace(str, end);
        if(begin == -1){
            outputWord(str, 0, end);
            return;
        } else {
            outputWord(str, begin + 1, end);
            end = begin - 1;
        }

    }

}

int main() {
    /**
     * case: Hello World Here I Come
     * result: Come I Here World Hello
     */
    solution();
    return 0;
}