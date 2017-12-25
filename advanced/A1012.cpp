#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int grade[4]; // 存放四门成绩，顺序为ACME
} stu[2001];

char course[4] = {'A', 'C', 'M', 'E'};
static int rank[1000000][4] = {0}; // rank[i][j]表示第i个学生的第j门课程的排名
int which; // 表示使用哪门成绩来对成绩排名

bool cmp(Student a, Student b) {
    return a.grade[which] > b.grade[which];
}

void solution() {

    int stu_cnt, q_cnt;
    cin >> stu_cnt >> q_cnt;

    // 输入学生信息
    for (int i = 0; i < stu_cnt; i++) {
        cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
        stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
    }

    for (which = 0; which < 4; which++) {

        sort(stu, stu + stu_cnt, cmp); // 根据一门成绩来排序
        ::rank[stu[0].id][which] = 1; // 将分数最高的排名设置为1

        // 处理其余排名的学生
        for (int j = 1; j < stu_cnt; j++) {
            if (stu[j].grade[which] == stu[j - 1].grade[which])
                ::rank[stu[j].id][which] = ::rank[stu[j - 1].id][which];
            else
                ::rank[stu[j].id][which] = j + 1;
        }
    }

    int query;
    for (int i = 0; i < q_cnt; i++) {
        cin >> query;
        if (::rank[query][0] == 0) {
            cout << "N/A\n";
        } else {
            int best = 0;
            for (int j = 1; j < 4; j++) {
                if (::rank[query][j] < ::rank[query][best]) {
                    best = j;
                }
            }
            cout << ::rank[query][best] << " " << course[best] << endl;
        }
    }

}

int main() {
    solution();
    return 0;
}
