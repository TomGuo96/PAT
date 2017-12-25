/**
 * 动态规划
 * 解法：《算法笔记》
 */
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Station {
    double price;
    double dist;
};

bool cmp(Station s1, Station s2) {
    return s1.dist < s2.dist;
}

void solution() {

    double tank, distance, avg;
    int size;
    cin>>tank>>distance>>avg>>size;

    double max_dist = avg * tank; // 表示加满油可以到达的最远距离

    Station sta[size + 1];
    for (int i = 0; i < size; i++) {
        cin>>sta[i].price>>sta[i].dist;
    }
    sta[size].price = 0;
    sta[size].dist = distance;

    sort(sta, sta + size, cmp); // 按离出发点距离的升序排序

    // 出发地没有加油站，无法出发
    if (sta[0].dist != 0) {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return;
    }
    int cur_sta = 0; // 表示现在在哪个加油站
    double res = 0; // 总花费
    double tank_now = 0; // 当前油量

    while (cur_sta < size) {

        int k = -1; // 最低价加油站的编号
        double min_price = INT_MAX; // 最低油价
        // 选出下一个加油站
        for (int i = cur_sta + 1; i <= size && sta[i].dist - sta[cur_sta].dist <= max_dist; i++) {
            if (sta[i].price < min_price) {
                min_price = sta[i].price;
                k = i;
                if (min_price < sta[cur_sta].price)
                    break;
            }
        }

        // 找不到符合题条件的加油站，直接退出
        if (k == -1)
            break;

        double need = (sta[k].dist - sta[cur_sta].dist) / avg; // 计算到达下一站的所需油量

        if (min_price < sta[cur_sta].price) {
            if (tank_now < need) {
                res += (need - tank_now) * sta[cur_sta].price;
                tank_now = 0;
            } else {
                tank_now -= need;
            }
        } else {
            res += (tank - tank_now) * sta[cur_sta].price;
            tank_now = tank - need;
        }

        cur_sta = k;
    }

    if (cur_sta == size)
        cout<<fixed<<setprecision(2)<<res<<endl;
    else
        cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<sta[cur_sta].dist + max_dist<<endl;

}

int main() {
    solution();
    return 0;
}