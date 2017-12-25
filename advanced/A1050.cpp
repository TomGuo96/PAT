#include <iostream>
#include <cstring>

using namespace std;

void solution(){
    int size = 10001;
    char s1[size], s2[size];
    cin.getline(s1, size);
    cin.getline(s2, size);

    bool hasChar[128];
    for(int i = 0; i < 128;i++)
        hasChar[i] = false;

    for(int i = 0; i < strlen(s2);i++)
        hasChar[(int)s2[i]] = true;

    for(int i = 0; i < strlen(s1); i++){
        if(!hasChar[(int)s1[i]])
            cout<<s1[i];
    }
    cout<<endl;
}

int main() {
    /**
     * 测试用例：
     * They are students.
     * aeiou
     * 期待结果：
     * Thy r stdnts.
     */
    solution();
    return 0;
}