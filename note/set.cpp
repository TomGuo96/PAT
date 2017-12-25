//
// Created by Tom Guo on 09/10/2017.
//

#include <iostream>
#include <set>

using namespace std;

int main(){

    set<int> st;

    /* insert */

    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(4);
    st.insert(7);
    st.insert(6);
    st.insert(8);
    st.insert(-10);
    cout<<"初始化后：";
    for(set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* find */

    set<int>::iterator it = st.find(2);
    cout<<*it<<endl;

    /* erase */

    // 删除迭代器对应的元素
    st.erase(st.find(-10));
    cout<<"删除-10后：";
    for(set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    // 删除相应的值的元素
    st.erase(6);
    cout<<"删除6后：";
    for(set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    // 删除一个区间的元素
    st.erase(st.find(4), st.end());
    cout<<"删除4及以后的元素后：";
    for(set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* clear */

    st.clear();

    /* size */

    cout<<"删除全部元素后，set内有"<<st.size()<<"个元素。"<<endl;

    return 0;
}