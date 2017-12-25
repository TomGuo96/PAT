//
// Created by Tom Guo on 17/10/2017.
//

#include <iostream>

using namespace std;

/*
 * 输入数据：
 * 5 8
 * 3 5 1 2 2
 * 4 5 2 1 3
 * 5 8 3 5 1 2 2 4 5 2 1 3
 */

const int maxn = 30;
// 物品数量n，背包容量V，最大价值maxValue;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

/********
 * 版本一
 ********/

// index为当前处理的物品编号，sumW为当前总重量，sumC为当前总价值
void DFS1(int index, int sumW, int sumC){
    if(index == n){
        if(sumW <= V && sumC > maxValue)
            maxValue = sumC;
        return;
    }
    DFS1(index + 1, sumW, sumC);
    DFS1(index + 1, sumW + w[index], sumC + c[index]);
}

/********
 * 版本二
 ********/

void DFS2(int index, int sumW, int sumC){
    if(index == n)
        return;
    DFS2(index + 1, sumW, sumC);
    if(sumW + w[index] <= V){
        maxValue = sumC + c[index] > maxValue ? sumC + c[index] : maxValue;
        DFS2(index + 1, sumW + w[index], sumC + c[index]);
    }
}


int main(){

    cin>>n>>V;

    for(int i = 0; i < n; i++)
        cin>>w[i];
    for(int i = 0; i < n; i++)
        cin>>c[i];
    DFS2(0, 0, 0);
    cout<<maxValue;

    return 0;
}