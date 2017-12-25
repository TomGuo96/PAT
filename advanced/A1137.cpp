//
// Created by Tom Guo on 11/12/2017.
//

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct Student {

    string name;
    int id;
    double Gp, Gmid, Gfinal, G;

    Student() {
        G = Gp = Gmid = Gfinal = id = -1;
    }

    Student(string _name, int _id) {
        name = _name;
        G = Gp = Gmid = Gfinal = -1;
        id = _id;
    }

};

bool cmp(Student stu1, Student stu2) {
    if (stu1.G != stu2.G)
        return stu1.G > stu2.G;
    return stu1.name < stu2.name;
}

void solution() {

    int P, M, N;
    scanf("%d %d %d", &P, &M, &N);

    unordered_map<string, int> mp;
    vector<Student> stu;

    int count = 0; // 对学生计数
    double score;

    for (int i = 0; i < P; i++) {

        char str[25];
        scanf("%s %lf", str, &score);
        string name(str);
        mp.insert(make_pair(name, count));
        Student s(name, count++);
        s.Gp = score;
        stu.push_back(s);

    }

    for (int i = 0; i < M; i++) {

        char str[25];
        scanf("%s %lf", str, &score);
        string name(str);
        if (mp.find(name) != mp.end()) {
            int id = mp.find(name)->second;
            stu[id].Gmid = score;
        } else {
            mp.insert(make_pair(name, count));
            Student s(name, count++);
            s.Gmid = score;
            stu.push_back(s);
        }


    }

    for (int i = 0; i < N; i++) {

        char str[25];
        scanf("%s %lf", str, &score);
        string name(str);
        if (mp.find(name) != mp.end()) {
            int id = mp.find(name)->second;
            stu[id].Gfinal = score;
        } else {
            mp.insert(make_pair(name, count));
            Student s(name, count++);
            s.Gfinal = score;
            stu.push_back(s);
        }

    }

    // 计算每个学生的总分
    for (auto it = mp.begin(); it != mp.end(); it++) {

        int id = it->second;

        if (stu[id].Gmid != -1 && stu[id].Gfinal != -1)
            stu[id].G = round(0.4 * stu[id].Gmid + 0.6 * stu[id].Gfinal);

        if (stu[id].Gfinal > stu[id].Gmid)
            stu[id].G = stu[id].Gfinal;

    }

    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].Gp >= 200 && stu[i].G >= 60)
            printf("%s %d %d %d %d\n", stu[i].name.c_str(), (int) stu[i].Gp, (int) stu[i].Gmid, (int) stu[i].Gfinal,
                   (int) stu[i].G);
    }

}

int main() {
    solution();
    return 0;
}