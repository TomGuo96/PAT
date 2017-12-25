//
// Created by Tom Guo on 09/10/2017.
//

#include <iostream>
#include <map>

using namespace std;

void output(map<char, int>);

int main(){

    map<char, int> mp;

    mp['a'] = 1;
    mp['c'] = 7;
    mp['b'] = 10;
    mp['e'] = 4;
    mp['v'] = 1;

    /* 两种访问方式 */

    // 类似与传统数组
    cout<<"使用类似数组的方式访问：";
    cout<<mp['a']<<endl;

    // 使用迭代器
    cout<<"使用迭代器访问：";
    output(mp);

    /* find() */

    map<char, int>::iterator it = mp.find('b');
    cout<<"使用find函数: "<<it->first<<" "<<it->second<<endl;

    /* erase() */

    // 使用迭代器删除单个元素
    mp.erase(it);
    cout<<"用迭代器删除一个元素后："<<endl;
    output(mp);

    // 使用键来删除单个元素
    mp.erase('c');
    cout<<"用键来删除一个元素后"<<endl;
    output(mp);

    // 删除区间内的元素
    mp.erase(mp.find('e'), mp.end());
    cout<<"删除一个区间后："<<endl;
    output(mp);

    /* clear() */

    mp.clear();

    /* size() */

    cout<<"使用clear后，map还剩下"<<mp.size()<<"个元素。"<<endl;
}

void output(map<char, int> mp){
    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
    return;
}