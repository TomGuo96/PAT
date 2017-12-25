#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[10];
    int grade;
};

bool cmp1(Student s1, Student s2) {
    return s1.id < s2.id;
}

bool cmp2(Student s1, Student s2) {
    int res = strcmp(s1.name, s2.name);
    if (res != 0)
        return res < 0;
    return s1.id < s2.id;
}

bool cmp3(Student s1, Student s2) {
    if (s1.grade != s2.grade)
        return s1.grade < s2.grade;
    return s1.id < s2.id;
}

void solution() {

    int size, C;
    scanf("%d%d", &size, &C);

    Student stu[size];
    for (int i = 0; i < size; i++)
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);

    if (C == 1)
        sort(stu, stu + size, cmp1);
    else if (C == 2)
        sort(stu, stu + size, cmp2);
    else if (C == 3)
        sort(stu, stu + size, cmp3);

    for (int i = 0; i < size; i++)
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);

}


int main() {
    solution();
    return 0;
}