//
// Created by Tom Guo on 16/11/2017.
//

#include <cstdio>
#include <climits>

using namespace std;

// 查找[l...r)中第一个大于x的值
int upper_bound(int l, int r, int x, int arr[]) {
    int mid;
    while (l < r) {
        mid  = l + (r - l) / 2;
        if (arr[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solution() {

    int size, target;
    scanf("%d%d", &size, &target);
    int sum[size + 1];
    sum[0] = 0;
    for (int i = 1; i <= size; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    int near = INT_MAX;
    for (int i = 1; i <= size; i++) {
        int j = upper_bound(i, size + 1, sum[i - 1] + target, sum); // 求右端点
        if (sum[j - 1] - sum[i - 1] == target) {
            near = target;
            break;
        } else if (j <= size && sum[j] - sum[i - 1] < near)
            near = sum[j] - sum[i - 1];
    }

    for (int i = 1; i <= size; i++) {
        int j = upper_bound(i, size + 1, sum[i - 1] + near, sum);
        if (sum[j - 1] - sum[i - 1] == near)
            printf("%d-%d\n", i, j - 1);
    }

}

int main() {
    solution();
    return 0;
}