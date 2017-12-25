#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct mooncake {
    double storage;
    double sell;
    double price;
};

// 单价高的月饼在前
bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}

void solution() {

    int kinds, demand;
    cin >> kinds >> demand;

    mooncake mc[kinds];

    for (int i = 0; i < kinds; i++)
        cin >> mc[i].storage;
    for (int i = 0; i < kinds; i++) {
        cin >> mc[i].sell;
        mc[i].price = mc[i].sell / mc[i].storage;
    }

    // 按单价排序
    sort(mc, mc + kinds, cmp);

    double profit = 0;
    for (int i = 0; i < kinds; i++) {
        if (demand == 0)
            break;
        if (demand >= mc[i].storage) {
            profit += mc[i].sell;
            demand -= mc[i].storage;
            mc[i].storage = 0;
        } else if (demand < mc[i].storage) {
            profit += demand * mc[i].price;
            mc[i].storage -= demand;
            demand = 0;
        }
    }

    cout << fixed << setprecision(2) << profit << endl;

}

int main() {
    /**
     * 测试用例：
     * 3 20 18 15 10 75 72 45
     * 期待结果：
     * 94.50
     */
    solution();
    return 0;
}