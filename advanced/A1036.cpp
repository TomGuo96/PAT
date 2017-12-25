//
// Created by Tom Guo on 24/10/2017.
//

#include <iostream>

using namespace std;

void solution() {

    int size;
    cin>>size;

    string cur_name, lowest_name, highest_name, lowest_id, highest_id, cur_gender, cur_id;
    int cur_score ,lowest_score = 101, highest_score = -1;
    for (int i = 0; i < size; i++) {
        cin>>cur_name>>cur_gender>>cur_id>>cur_score;
        if (cur_gender == "M" && cur_score < lowest_score) {
            lowest_score = cur_score;
            lowest_id = cur_id;
            lowest_name = cur_name;
        }
        if (cur_gender == "F" && cur_score > highest_score) {
            highest_score = cur_score;
            highest_id = cur_id;
            highest_name = cur_name;
        }
    }


    if (highest_name.empty()) {
        cout<<"Absent"<<endl;
    } else {
        cout<<highest_name<<" "<<highest_id<<endl;
    }
    if (lowest_name.empty()) {
        cout<<"Absent"<<endl;
    } else {
        cout<<lowest_name<<" "<<lowest_id<<endl;
    }
    if (highest_name.empty() || lowest_name.empty()) {
        cout<<"NA\n";
    } else {
        cout<<highest_score - lowest_score<<endl;
    }

}

int main() {
    /**
     * 测试用例：
     * 3 Joe M Math990112 89 Mike M CS991301 100 Mary F EE990830 95
     * 期待结果：
     * Mary EE990830
     * Joe Math990112
     * 6
     */
    solution();
    return 0;
}