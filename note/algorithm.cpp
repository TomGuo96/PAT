//
// Created by Tom Guo on 10/10/2017.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    cout<<max(1, 2)<<endl;
    cout<<min(max(1, 2), 0)<<endl;
    cout<<abs(-10)<<endl;
    cout<<fabs(-1.34)<<endl;

    int x = 1, y = 3;
    swap(x, y);
    cout<<"x = "<<x<<" y = "<<y<<endl;

    /* reverse() */

    // 数组反转
    int a[] = {1, 2, 3, 4, 5};
    reverse(a, a + 3);
    cout<<"部分反转后的数组为：";
    for(int i = 0; i < 5; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    // string的反转
    string str = "abcdefg";
    reverse(str.begin(), str.end());
    cout<<"反转后的string为："<<str<<endl;

    fill(a, a + 3, 200);
    cout<<"使用fill函数填充后:";
    for(int i = 0; i < 5; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    /* lower_bound()和upper_bound() */

    int num[] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
    int *lower, *upper;

    lower = lower_bound(num, num + 10, -1);
    upper = upper_bound(num, num + 10, -1);
    cout<<"-1的结果为："<<lower - num<<", "<<upper - num<<endl;
    lower = lower_bound(num, num + 10, 1);
    upper = upper_bound(num, num + 10, 1);
    cout<<"1的结果为："<<lower - num<<", "<<upper - num<<endl;
    lower = lower_bound(num, num + 10, 2);
    upper = upper_bound(num, num + 10, 2);
    cout<<"2的结果为："<<lower - num<<", "<<upper - num<<endl;
    lower = lower_bound(num, num + 10, 5);
    upper = upper_bound(num, num + 10, 5);
    cout<<"5的结果为："<<lower - num<<", "<<upper - num<<endl;

    return 0;
}