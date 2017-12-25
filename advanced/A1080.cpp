//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    int GE, GI, sum;
    int rank, id;
    int choice[6];
} stu[40001];

struct School {
    int quota; // 招生总额
    int stu_cnt; // 实际招生人数
    int id[40001]; // 招生学生的编号
    int last_id; // 最后一个招收的学生的编号
} sch[101];

bool cmpStu(Student s1, Student s2) {
    if (s1.sum != s2.sum)
        return s1.sum > s2.sum;
    return s1.GE > s2.GE;
}

bool cmpId(int x, int y) {
    return stu[x].id < stu[y].id;
}

void solution() {

    int stu_cnt, sch_cnt, m; // m表示每人可申请的学校的数量
    cin >> stu_cnt >> sch_cnt >> m;

    // 初始化学校
    for (int i = 0; i < sch_cnt; i++) {
        cin >> sch[i].quota;
        sch[i].stu_cnt = 0;
        sch[i].last_id = -1;
    }

    // 初始化考生
    for (int i = 0; i < stu_cnt; i++) {
        stu[i].id = i;
        cin >> stu[i].GE >> stu[i].GI;
        stu[i].sum = stu[i].GE + stu[i].GI;
        for (int j = 0; j < m; j++)
            cin >> stu[i].choice[j];
    }

    sort(stu, stu + stu_cnt, cmpStu); // 对考生按成绩排序

    // 计算考生的排名
    for (int i = 0; i < stu_cnt; i++) {
        if (i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = i;
    }

    // 对每一名同学尝试录取
    for (int i = 0; i < stu_cnt; i++) {

        // 对一名同学的每个学校查看是否可以录取
        for (int j = 0; j < m; j++) {

            int chc = stu[i].choice[j];
            int num = sch[chc].stu_cnt; // 该学校当前招生了的人数
            int last_one = sch[chc].last_id;

            // 人数不满或与最后一名录取考生的名次相同时
            if (num < sch[chc].quota || (last_one != -1 && stu[i].rank == stu[last_one].rank)) {
                sch[chc].id[num] = i;
                sch[chc].last_id = i;
                sch[chc].stu_cnt++;
                break;
            }
        }
    }

    for (int i = 0; i < sch_cnt; i++) {
        if (sch[i].stu_cnt > 0) { // 该学校招到了学生

            sort(sch[i].id, sch[i].id + sch[i].stu_cnt, cmpId);
            for (int j = 0; j < sch[i].stu_cnt; j++) {
                cout << stu[sch[i].id[j]].id;
                if (j < sch[i].stu_cnt - 1)
                    cout << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    solution();
    return 0;
}