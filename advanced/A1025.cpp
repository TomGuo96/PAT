#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/**
 * 解法来自《算法笔记》
 */

struct Student {
    char id[15];
    int score;
    int local_number;
    int local_rank;
} stu[30000];

bool cmp(Student a, Student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

void solution() {

    // num为总考生号，n为考场数，k为考场内人数
    int n, k, num = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].local_number = i;
            num++;
        }

        // 将考场内的考生排序
        sort(stu + num - k, stu + num, cmp);

        // 对第一位考生排名置为1
        stu[num - k].local_rank = 1;
        for (int j = num - k + 1; j < num; j++) {
            if (stu[j].score == stu[j - 1].score)
                stu[j].local_rank = stu[j - 1].local_rank;
            else
                stu[j].local_rank = j + 1 - (num - k);

        }
    }

    printf("%d\n", num);
    sort(stu, stu + num, cmp);

    int r = 1;
    for (int i = 0; i < num; i++) {
        if (i > 0 && stu[i].score != stu[i - 1].score)
            r = i + 1;
        printf("%s %d %d %d\n", stu[i].id, r, stu[i].local_number, stu[i].local_rank);
    }

}

int main() {
    /**
     * 测试用例：
     * 2 5 1234567890001 95 1234567890005 100 1234567890003 95 1234567890002 77 1234567890004 85 4 1234567890013 65 1234567890011 25 1234567890014 100 1234567890012 85
     * 期待结果：
     * 9
     * 12345678900051 1 1
     * 12345678900141 2 1
     * 12345678900013 1 2
     * 12345678900033 1 2
     * 12345678900045 1 4
     * 12345678900125 2 2
     * 12345678900027 1 5
     * 12345678900138 2 3
     * 12345678900119 2 4
     */
    solution();
    return 0;
}
