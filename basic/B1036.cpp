#include <iostream>

using namespace std;

// 输出一行ch1ch2ch2ch2ch1型
void output(char ch1, char ch2, int size){
    cout<<ch1;
    for(int i = 0; i < size - 2; i++)
        cout<<ch2;
    cout<<ch1<<endl;
}

void solution(){

    int rows, cols;
    char ch;
    cin>>cols>>ch;
    rows = (cols % 2 == 0) ? cols / 2 : (cols + 1) / 2;

    output(ch, ch, cols);

    for(int i = 0; i < rows - 2; i++)
        output(ch, ' ', cols);

    output(ch, ch, cols);

}

int main() {
    /**
     * case: 10 x
     * 期待结果：
     * xxxxxxxxxx
     * x        x
     * x        x
     * x        x
     * xxxxxxxxxx
     */
    solution();
    return 0;
}