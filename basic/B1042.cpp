//
// Created by Tom Guo on 26/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    string s;
    getline(cin, s);

    int count[128]= {0};
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            if (s[i] <= 'Z')
                count[s[i] + 32]++;
            else
                count[s[i]]++;
        }
    }

    char letter;
    int max_count = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (count[i] > max_count) {
            letter = i;
            max_count = count[i];
        }
    }

    cout<<letter<<" "<<max_count<<endl;
}

int main() {
    /*
     * 测试用例：
     * This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
     * 期待结果：
     * e 7
     */
    solution();
    return 0;
}