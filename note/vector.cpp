//
// Created by Tom Guo on 09/10/2017.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> vec;
    // 初始化一个有10个元素的向量
    for(int i = 0; i < 10; i++)
        vec.push_back(i + 1);

    /* 访问vector内的元素 */

    vector<int>::iterator it = vec.begin();
    for(int i = 0; i < 10; i++)
        cout<<*(it + i)<<" ";
    cout<<endl;

    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";
    cout<<endl<<endl;

    /* pop_back() */

    vec.pop_back();
    cout<<"删除最后一个元素后：";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* size() */

    cout<<"该vector现在中共有"<<vec.size()<<"个元素。"<<endl;

    /* insert() */

    vec.insert(vec.begin() + 3, -66);
    cout<<"新插入一个元素后：";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* erase() */

    // 删除制定迭代器对应的元素
    vec.erase(vec.begin() + 5);
    cout<<"删除第6元素后：";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    // 删除迭代器区间内的元素
    vec.erase(vec.begin() + 1, vec.begin() + 3);
    cout<<"删除[1, 3)区间后：";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* clear() */

    vec.clear();
    cout<<"使用clear()函数后，该vector现在有"<<vec.size()<<"个元素。"<<endl;

}