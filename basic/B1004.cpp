//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int size;
    cin>>size;

    string max_name, min_name, cur_name, max_id, min_id, cur_id;
    int max_score = -1, min_score = 101, cur_score;
    for (int i = 0; i < size; i++) {
        cin>>cur_name>>cur_id>>cur_score;
        if (cur_score > max_score) {
            max_name = cur_name;
            max_id = cur_id;
            max_score = cur_score;
        }
        if (cur_score < min_score) {
            min_name = cur_name;
            min_id = cur_id;
            min_score = cur_score;
        }
    }

    cout<<max_name<<" "<<max_id<<endl;
    cout<<min_name<<" "<<min_id<<endl;

}

int main() {
    /**
     * 测试用例：
     * 3 Joe Math990112 89 Mike CS991301 100 Mary EE990830 95
     * 期待结果：
     * Mike CS991301
     * Joe Math990112
     */
    solution();
    return 0;
}