//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rich {
    string name;
    int age;
    int wealth;
};

bool cmp(rich r1, rich r2) {
    if (r1.wealth != r2.wealth)
        return r1.wealth > r2.wealth;
    else if (r1.age != r2.age)
        return r1.age < r2.age;
    else
        return r1.name < r2.name;
}

void solution() {

    int people_count, queries;
    cin >> people_count >> queries;

    rich rich_list[people_count];
    for (int i = 0; i < people_count; i++)
        cin >> rich_list[i].name >> rich_list[i].age >> rich_list[i].wealth;

    sort(rich_list, rich_list + people_count, cmp);

    vector<int> valid_list;
    int valid[210] = {0};
    for (int i = 0; i < people_count; i++) {
        int age = rich_list[i].age;
        if (valid[age] < 100) {
            valid_list.push_back(i);
            valid[age]++;
        }
    }

    for (int i = 0; i < queries; i++) {
        int top, floor, roof, count = 0; // count为已经输出个数，top为需要输出的个数
        cin >> top >> floor >> roof;
        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0; j < valid_list.size(); j++) {
            if (rich_list[valid_list[j]].age >= floor && rich_list[valid_list[j]].age <= roof) {
                cout << rich_list[valid_list[j]].name << " " << rich_list[valid_list[j]].age << " "
                     << rich_list[valid_list[j]].wealth << endl;
                count++;
            }
            if (count == top)
                break;
        }
        if (count == 0)
            cout << "None\n";
    }

}

int main() {
    solution();
    return 0;
}